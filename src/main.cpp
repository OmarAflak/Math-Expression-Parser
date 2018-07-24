#include <iostream>
#include <chrono>
#include "../include/processor.h"

void test(){
    std::string expression = "x^2 + exp(y)";
    std::cout << Processor::evaluate(expression, {{"x", 3}, {"y", 2}}) << std::endl;
}

int measure(void (*function)(void)){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    function();
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
}

int main(int argc, char const *argv[]) {
    int t = measure(test);
    std::cout << std::endl << "execution time : " << t << "us" << std::endl;
    return 0;
}
