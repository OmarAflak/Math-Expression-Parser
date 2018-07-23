#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "1+2^3";
    // std::string expression = "1+4*sin(5)-pow(2,3)";
    std::unordered_map<std::string, double> map = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::cout << Processor::preprocess(expression, map) << std::endl;
    return 0;
}
