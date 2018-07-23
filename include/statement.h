#ifndef STATEMENT
#define STATEMENT

#include "uid.h"
#include "utils.h"
#include "functions.h"

#include <unordered_map>
#include <stdexcept>

class Statement {
    private:
        std::string uid;
        std::string opr;
        std::string left, right;

        double process(std::string token, const std::unordered_map<std::string, double>& map) const;

    public:
        Statement();
        Statement(std::string left);
        Statement(std::string left, std::string right, std::string opr);

        double evaluate(const std::unordered_map<std::string, double>& map) const;
};

#endif
