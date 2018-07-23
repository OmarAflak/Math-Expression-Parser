#include "../include/token.h"

Token::Token(){
    fun = "self";
}

Token::Token(std::string token){
    this->fun = "self";
    this->token = token;
}

Token::Token(std::string fun, std::string token){
    this->fun = fun;
    this->token = token;
}

std::string Token::function() const{
    return fun;
}

std::string Token::name() const{
    return token;
}

double Token::process(const std::unordered_map<std::string, double>& map) const{
    if(map.find(token)==map.end()){
        return toNumber(token);
    }
    return map.at(token);
}

double Token::evaluate(const std::unordered_map<std::string, double>& map) const{
    double value = process(map);

    if (fun == _EXP)
        return exp(value);
    if (fun == _LOG)
        return log(value);
    if (fun == _COS)
        return cos(value);
    if (fun == _SIN)
        return sin(value);
}
