#include "../include/utils.h"

void removeAllSpaces(std::string& str){
    std::string s;
    for(const char& c : str){
        if(c!=' '){
            s+=c;
        }
    }
    str = s;
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
