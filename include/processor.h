#ifndef PROCESSOR
#define PROCESSOR

#include "statement.h"

class Processor {
    public:
        static double evaluate(std::string expression, const std::unordered_map<std::string, double>& map, bool expr=false);
        static double evaluateExpr(std::string expression, const std::unordered_map<std::string, double>& map);
        static std::string preprocess(std::string expression, const std::unordered_map<std::string, double>& map);
};

#endif
