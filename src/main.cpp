#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "(x+y)^2";
    std::unordered_map<std::string, double> map = {{"x", 1}, {"y", 2}};
    std::cout << Processor::evaluate(expression, map) << std::endl;
    return 0;
}
