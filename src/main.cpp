#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "6+(x+exp((x+x)*sin(1.57079633))^2)*3";
    std::unordered_map<std::string, double> map = {{"x", 1}, {"y", 0}};
    std::cout << Processor::evaluate(expression, map, true) << std::endl;
    return 0;
}
