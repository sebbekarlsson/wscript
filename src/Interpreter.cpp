#include "includes/Interpreter.hpp"
#include <ctype.h>


Interpreter::Interpreter(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_token = nullptr;
};


Token* Interpreter::get_next_token() {
    if (this->pos > (int)this->text.length() - 1)
        return new Token(T_EOF, "");

    const char& current_char = this->text[this->pos];

    if (isdigit(current_char)) {
        Token* token = new Token(T_INTEGER, current_char + "");
        this->pos += 1;
        return token;
    }

    if (current_char == '+') {
        Token* token = new Token(T_PLUS, current_char + "");
        this->pos += 1;
        return token;
    }

    return nullptr; // TODO: raise error here
};

void Interpreter::eat(std::string token_type) {
    if (this->current_token->type == token_type) {
        this->current_token = this->get_next_token();
    } else {
        // TODO: raise error here
    }
};

std::string Interpreter::expr() {
    return "";
};
