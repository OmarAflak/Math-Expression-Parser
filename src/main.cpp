#include <iostream>
#include "../include/processor.h"

int main(int argc, char const *argv[]) {
    std::string expression = "lambda*best + some - 1";
    std::unordered_map<std::string, double> map = {{"lambda", 2.0}, {"best", 1.5}, {"some", 8}};
    std::cout << Processor::evaluate(expression, map) << std::endl;
    return 0;
}
