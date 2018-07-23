#ifndef PROCESSOR
#define PROCESSOR

#include "statement.h"

class Processor {
    public:
        static double evaluate(std::string expression, const std::unordered_map<std::string, double>& map);
        static double evaluateExpr(std::string expression, const std::unordered_map<std::string, double>& map);
        static bool isKnown(std::string expression, const std::unordered_map<std::string, double>& map);
};

#endif
