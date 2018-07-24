#include "../include/utils.h"

void removeAllSpaces(std::string& str){
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
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
    ss << std::fixed << n;
    return ss.str();
}
