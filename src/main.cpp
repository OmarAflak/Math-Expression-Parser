#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "a+c^b-5+a*b/c";
    std::unordered_map<std::string, double> map = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::cout << Processor::evaluate(expression, map) << std::endl;
    return 0;
}
