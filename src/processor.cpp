#include "../include/processor.h"

double Processor::evaluate(std::string expression, const std::unordered_map<std::string, double>& map){
    removeAllSpaces(expression);
    return evaluateExpr(expression, map);
}

double Processor::evaluateExpr(std::string expression, const std::unordered_map<std::string, double>& map){
    int ldel = expression.find_last_of(_LDEL);
    int rdel = expression.find_first_of(_RDEL, ldel);
    bool evaluateComplex = false;

    if(ldel!=-1 && rdel!=-1){
        std::string expr = expression.substr(ldel+1, rdel-ldel-1);
        if(isKnown(expr, map)){
            for(const std::string& fun : _functions){
                if(ldel>=fun.size() && ldel+fun.size()<expression.size()){
                    if(expression.substr(ldel-fun.size(), fun.size())==fun){
                        Token token(fun, expr);
                        expression = expression.substr(0, ldel-fun.size()) + toString(token.evaluate(map)) + expression.substr(rdel+1);
                        std::cout << "expr1 = [" << expression << "]" << std::endl;
                        return evaluateExpr(expression, map);
                    }
                }
            }

            expression = expression.substr(0, ldel) + toString(Token(expr).evaluate(map)) + expression.substr(rdel+1);
            std::cout << "expr2 = [" << expression << "]" << std::endl;
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
        int start = (ldel==-1?0:ldel);
        int end = (rdel==-1?expression.size():rdel);

        for(int i=start ; i<end ; i++){
            if(_operations.find(expression[i])!=_operations.end()){
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

                std::string lexpr = expression.substr(left+1, i-left-1);
                std::string rexpr = expression.substr(i+1, right-i-1);
                Statement statement(lexpr, rexpr, expression[i]);
                expression = expression.substr(0, left+1) + toString(statement.evaluate(map)) + (right<expression.size()?expression.substr(right):"");
                std::cout << "expr3 = [" << expression << "]" << std::endl;
                return evaluateExpr(expression, map);
            }
        }
    }

    return toNumber(expression);
}

bool Processor::isKnown(std::string expression, const std::unordered_map<std::string, double>& map){
    if(map.find(expression)==map.end()){
        if(!isNumber(expression)){
            return false;
        }
    }
    return true;
}

// std::string Processor::preprocess(std::string expression, const std::unordered_map<std::string, double>& map){
//     int i=0;
//     while(true){
//         bool parentheses = false;
//
//         // find operator index
//         if((i=expression.find(_LDEL))!=-1){
//             int max = expression.find(_RDEL, i);
//             for(int j=i ; j<=max ; j++){
//                 if(_op_functions.find(expression[j])!=_op_functions.end()){
//                     i = j;
//                     parentheses = true;
//                     break;
//                 }
//                 i = -1;
//             }
//         }
//
//         if(i==-1){
//             for(const char& op : _op_priorities){
//                 if((i=expression.find(op))!=-1){
//                     break;
//                 }
//                 i = -1;
//             }
//         }
//
//         if(i==-1){
//             for(int j=0 ; j<expression.size() ; j++){
//                 if(_op_functions.find(expression[j])!=_op_functions.end()){
//                     i = j;
//                     break;
//                 }
//                 i = -1;
//             }
//         }
//
//         if(i==-1)
//             return expression;
//
//         // find left/right member expression
//         int left, right;
//
//         for(left=i-1 ; left>=0 ; left--){
//             if(_op_functions.find(expression[left])!=_op_functions.end()){
//                 break;
//             }
//         }
//
//         for(right=i+1 ; right<expression.size() ; right++){
//             if(_op_functions.find(expression[right])!=_op_functions.end()){
//                 break;
//             }
//         }
//
//         // rewrite expression
//         int p = parentheses?1:0;
//         std::string lexpr = expression.substr(left+1+p, i-left-1-p);
//         std::string rexpr = expression.substr(i+1, right-i-1-p);
//         std::string fun = _op_map_functions.at(expression[i])+_LDEL+lexpr+_SEP+rexpr+_RDEL;
//         expression = expression.substr(0, left+1) + fun + (right<expression.size()?expression.substr(right):"");
//     }
// }
