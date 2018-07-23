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
