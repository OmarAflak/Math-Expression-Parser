#include "../include/processor.h"

#include <iostream>
double Processor::evaluate(std::string expression, const std::unordered_map<std::string, double>& map){
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

            std::string lexpr = trim(expression.substr(left+1, comma-left-1));
            std::string rexpr = trim(expression.substr(comma+1, right-comma-1));

            Statement statement(lexpr, rexpr, opr);
            expression = expression.substr(0, left-opr.size())+toString(statement.evaluate(map))+expression.substr(right+1);

            // std::cout << "lexpr = [" << lexpr << "]" << std::endl;
            // std::cout << "rexpr = [" << rexpr << "]" << std::endl;
            // std::cout << "opr = [" << opr << "]" << std::endl;
            // std::cout << "new expr = [" << expression << "]" << std::endl;

            return evaluate(expression, map);
        }
        else{
            throw std::invalid_argument("Invalid expression, missing comma : "+expression);
        }
    }

    return toNumber(expression);
}
