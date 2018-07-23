#include "../include/processor.h"

double Processor::evaluate(std::string expression, const std::unordered_map<std::string, double>& map, bool expr){
    removeAllSpaces(expression);
    if(!expr){
        expression = preprocess(expression, map);
    }
    return evaluateExpr(expression, map);
}

double Processor::evaluateExpr(std::string expression, const std::unordered_map<std::string, double>& map){
    int left = expression.find_last_of(_LDEL);
    int right = expression.find_first_of(_RDEL, left);
    int comma = expression.find(_SEP, left);

    if(left!=-1 && right!=-1){
        if(comma>left && comma<right){
            int p = left;
            std::string opr = "";

            while(p>=0){
                if(_functions.find(expression.substr(p, left-p))!=_functions.end()){
                    opr = expression.substr(p, left-p);
                    break;
                }
                p--;
            }

            if(opr==""){
                throw std::invalid_argument("Invalid expression, missing function : "+expression);
            }

            std::string lexpr = expression.substr(left+1, comma-left-1);
            std::string rexpr = expression.substr(comma+1, right-comma-1);

            Statement statement(lexpr, rexpr, opr);
            expression = expression.substr(0, left-opr.size())+toString(statement.evaluate(map))+expression.substr(right+1);
            return evaluateExpr(expression, map);
        }
        else{
            throw std::invalid_argument("Invalid expression, missing comma : "+expression);
        }
    }

    return toNumber(expression);
}

std::string Processor::preprocess(std::string expression, const std::unordered_map<std::string, double>& map){
    for(const char& op : _op_priorities){
        int i,p=0;
        while((i=expression.find(op, p))!=-1){
            int left, right;

            for(left=i-1 ; left>=0 ; left--){
                if(_op_functions.find(expression[left])!=_op_functions.end()){
                    break;
                }
            }

            for(right=i+1 ; right<expression.size() ; right++){
                if(_op_functions.find(expression[right])!=_op_functions.end()){
                    break;
                }
            }

            std::string lexpr = expression.substr(left+1, i-left-1);
            std::string rexpr = expression.substr(i+1, right-i-1);
            std::string fun = _op_map_functions.at(expression[i])+_LDEL+lexpr+_SEP+rexpr+_RDEL;
            expression = expression.substr(0, left+1) + fun + (right<expression.size()?expression.substr(right):"");
            p = i+1;
        }
    }
    return expression;
}
