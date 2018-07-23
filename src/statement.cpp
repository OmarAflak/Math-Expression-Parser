#include "../include/statement.h"

Statement::Statement(){}

Statement::Statement(std::string left, std::string right, std::string opr){
    this->left = left;
    this->right = right;
    this->opr = opr;
}

double Statement::process(std::string token, const std::unordered_map<std::string, double>& map) const{
    if(map.find(token)==map.end()){
        if(isNumber(token)){
            return toNumber(token);
        }
        else{
            throw std::invalid_argument("Invalid expression : "+token);
        }
    }
    return map.at(token);
}

double Statement::evaluate(const std::unordered_map<std::string, double>& map) const{
    double a = process(left, map);
    double b = process(right, map);

    if (opr == _ADD)
        return a + b;
    if (opr == _SUBTRACT)
        return a - b;
    if (opr == _MULTIPLY)
        return a * b;
    if (opr == _DIVIDE)
        return a / b;
    if (opr == _POWER)
        return pow(a,b);
}

double Statement::differentiate(bool withRespectToLeft, const std::unordered_map<std::string, double>& map) const{
    double a = process(left, map);
    double b = process(right, map);

    if (opr == _ADD)
        return 1;
    if (opr == _SUBTRACT)
        return withRespectToLeft?1:-1;
    if (opr == _MULTIPLY)
        return withRespectToLeft?b:a;
    if (opr == _DIVIDE)
        return withRespectToLeft?1/b:-a/(b*b);
    if (opr == _POWER)
        return withRespectToLeft?b*pow(a,b-1):log(a)*exp(b*log(a));
}
