#include "includes/cout.hpp"
#include <sstream>


void coutprint_char(char value) {
    std::stringstream ss;
    std::string target;
    ss << value;
    ss >> target;
    std::cout << target << std::endl;
};

void coutprint(anything value) {
    if (value.type() == typeid(std::string))
        coutprint(boost::get<std::string>(value));
    else if (value.type() == typeid(char))
        coutprint_char((char)boost::get<char>(value));
    else if (value.type() == typeid(int))
        coutprint(boost::get<int>(value));
    else if (value.type() == typeid(float))
        coutprint(boost::get<float>(value));
    else if (value.type() == typeid(bool))
        coutprint(boost::get<bool>(value));
    else if (value.type() == typeid(AST*))
        coutprint(boost::get<AST*>(value));
    else
        std::cout << "anything" << std::endl;
};

void coutprint(std::string value) {
    std::cout << value << std::endl;
};

void coutprint(int value) {
    std::cout << value << std::endl;
};

void coutprint(float value) {
    std::cout << value << std::endl;
};

void coutprint(bool value) {
    std::cout << value << std::endl;
};

void coutprint(AST* value) {
    std::cout << value << std::endl;
};
