#ifndef STATEMENT
#define STATEMENT

#include "utils.h"
#include "token.h"
#include "functions.h"

#include <unordered_map>
#include <stdexcept>
#include <cmath>

class Statement {
    private:
        char opr;
        Token left, right;

    public:
        Statement();
        Statement(Token left, Token right, char opr);

        double evaluate(const std::unordered_map<std::string, double>& map) const;
        double differentiate(bool withRespectToLeft, const std::unordered_map<std::string, double>& map) const;
};

#endif
