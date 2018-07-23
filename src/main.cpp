#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "add(add(add(a, b), c), multiply(d,e))";
    std::unordered_map<std::string, double> map = {{"a", 2.5}, {"b", 1.5}, {"c", 8}, {"e", 5}, {"d", 4}};
    std::cout << Processor::evaluate(expression, map) << std::endl;
    return 0;
}
