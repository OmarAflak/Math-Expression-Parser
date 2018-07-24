#ifndef TOKEN
#define TOKEN

#include "utils.h"
#include "functions.h"

#include <string>
#include <cmath>
#include <unordered_map>

class Token {
    private:
        std::string fun;
        std::string token;

    public:
        Token();
        Token(std::string token);
        Token(std::string fun, std::string token);

        std::string name() const;
        std::string function() const;

        double process(const std::unordered_map<std::string, double>& map) const;
        double evaluate(const std::unordered_map<std::string, double>& map) const;
        double differentiate(const std::string& var, const std::unordered_map<std::string, double>& map) const;
};

#endif
