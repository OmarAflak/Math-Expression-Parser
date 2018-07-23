#ifndef PROCESSOR
#define PROCESSOR

#include "statement.h"

class Processor {
    public:
        static double evaluate(std::string expression, const std::unordered_map<std::string, double>& map);
        static double evaluateRecursive(std::string expression, const std::unordered_map<std::string, double>& map);
        static std::string preprocess(std::string expression, const std::unordered_map<std::string, double>& map);
};

#endif
