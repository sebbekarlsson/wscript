#include "includes/Token.hpp"


Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
};

Token::~Token() {
    this->value = "";
};

std::string Token::get_string() {
    return this->value;
};

int Token::get_integer() {
    return std::stoi(this->value);
};

float Token::get_float() {
    return std::stof(this->value);
};
