#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "a*b + c - 1";
    std::unordered_map<std::string, double> map = {{"a", 2.0}, {"b", 1.5}, {"c", 8}};
    expression = Processor::preprocess(expression, map);
    std::cout << Processor::evaluate(expression, map) << std::endl;
    return 0;
}
