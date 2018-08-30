#include "includes/Interpreter.hpp"


Interpreter::Interpreter(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_token = nullptr;
};


Token* Interpreter::get_next_token() {
    return nullptr;
};

void Interpreter::eat(std::string token_type) {

};

std::string Interpreter::expr() {
    return "";
};
