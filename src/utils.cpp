#include "../include/utils.h"

std::string trim(const std::string& str){
    int a = str.find_first_not_of(" ");
    int b = str.find_last_not_of(" ");
    return str.substr(a, b-a+1);
}

bool isNumber(const std::string& str){
    for(const char& c : str){
        if(charInNumber.find(c)==charInNumber.end()){
            return false;
        }
    }
    return true;
}

double toNumber(const std::string& str){
    std::stringstream ss(str);
    double n;
    ss >> n;
    return n;
}

std::string toString(double n){
    std::stringstream ss;
    ss << n;
    return ss.str();
}
