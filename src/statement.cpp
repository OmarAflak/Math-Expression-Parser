#include "../include/statement.h"

Statement::Statement(){}

Statement::Statement(Token left, Token right, char opr){
    this->left = left;
    this->right = right;
    this->opr = opr;
}

double Statement::evaluate(const std::unordered_map<std::string, double>& map) const{
    double a = left.evaluate(map);
    double b = right.evaluate(map);

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

double Statement::differentiate(const std::string& var, const std::unordered_map<std::string, double>& map) const{
    double l = left.evaluate(map);
    double r = right.evaluate(map);
    double lprime = left.differentiate(var, map);
    double rprime = right.differentiate(var, map);

    if (opr == _ADD)
        return lprime + rprime;
    if (opr == _SUBTRACT)
        return lprime - rprime;
    if (opr == _MULTIPLY)
        return l*rprime + r*lprime;
    if (opr == _DIVIDE)
        return (lprime*r - l*rprime) / (r*r);
    if (opr == _POWER)
        return r*lprime*pow(l, r-1);
}
