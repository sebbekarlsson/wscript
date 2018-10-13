#include "includes/cout.hpp"


void coutprint(anything value) {
    if (value.type() == typeid(std::string))
        coutprint(boost::get<std::string>(value));
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
