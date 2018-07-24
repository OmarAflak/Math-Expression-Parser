#include "../include/processor.h"

double Processor::evaluate(const std::string& expression, const std::unordered_map<std::string, double>& map){
    std::string expCopy = expression;
    removeAllSpaces(expCopy);
    return evaluateExpr(expCopy, map);
}

double Processor::evaluateExpr(std::string expression, const std::unordered_map<std::string, double>& map){
    int ldel = expression.find_last_of(_LDEL);
    int rdel = expression.find_first_of(_RDEL, ldel);
    bool evaluateComplex = false;

    if(ldel!=-1 && rdel!=-1){
        std::string expr = expression.substr(ldel+1, rdel-ldel-1);
        if(isKnown(expr, map)){
            for(const std::string& fun : _functions){
                if(ldel>=fun.size()){
                    if(expression.substr(ldel-fun.size(), fun.size())==fun){
                        Token token(fun, expr);
                        expression = expression.substr(0, ldel-fun.size()) + toString(token.evaluate(map)) + expression.substr(rdel+1);
                        return evaluateExpr(expression, map);
                    }
                }
            }

            expression = expression.substr(0, ldel) + toString(Token(expr).evaluate(map)) + expression.substr(rdel+1);
            return evaluateExpr(expression, map);
        }
        else{
            evaluateComplex = true;
        }
    }
    else{
        evaluateComplex = true;
    }

    if(evaluateComplex){
        if(isKnown(expression, map)){
            return Token(expression).evaluate(map);
        }

        int start = (ldel==-1?0:ldel);
        int end = (rdel==-1?expression.size():rdel);
        int i;

        // search for operators
        for(const char& op : _operations_prio){
            for(int j=start ; j<end ; j++){
                if(expression[j]==op){
                    i = j;
                    break;
                }
                i=-1;
            }
            if(i!=-1)
                break;
        }

        if(i==-1){
            for(i=start ; i<end ; i++){
                if(_operations.find(expression[i])!=_operations.end()){
                    break;
                }
            }
        }

        // extract left/right members
        int left, right;
        for(left=i-1 ; left>=0 ; left--){
            if(_operations.find(expression[left])!=_operations.end() || expression[left]==_LDEL){
                break;
            }
        }

        for(right=i+1 ; right<expression.size() ; right++){
            if(_operations.find(expression[right])!=_operations.end() || expression[right]==_RDEL){
                break;
            }
        }

        // rewrite expression
        std::string lexpr = expression.substr(left+1, i-left-1);
        std::string rexpr = expression.substr(i+1, right-i-1);
        Statement statement(lexpr, rexpr, expression[i]);
        expression = expression.substr(0, left+1) + toString(statement.evaluate(map)) + (right<expression.size()?expression.substr(right):"");
        return evaluateExpr(expression, map);
    }
}

bool Processor::isKnown(std::string expression, const std::unordered_map<std::string, double>& map){
    if(map.find(expression)==map.end()){
        if(!isNumber(expression)){
            return false;
        }
    }
    return true;
}
