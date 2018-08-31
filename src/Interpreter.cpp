#include "includes/TOKEN_TYPES.h"
#include "includes/Interpreter.hpp"
#include <ctype.h>
#include <iostream>


Interpreter::Interpreter(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_token = nullptr;
    this->current_char = this->text.at(this->pos);
};

Token* Interpreter::get_next_token() {
    while (this->current_char != '\0') {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }

        if (isdigit(this->current_char))
            return new Token(T_INTEGER, std::to_string(this->integer()));

        if (this->current_char == '+') {
            this->advance();
            return new Token(T_PLUS, "+");
        }

        if (this->current_char == '-') {
            this->advance();
            return new Token(T_MINUS, "-");
        }

        // TODO raise error here
    }

    return new Token(T_EOF, "");
};

int Interpreter::integer() {
    std::string result = "";

    while (this->current_char != '\0' && isdigit(this->current_char)) {
        result += this->current_char;
        this->advance();
    }

    return std::stoi(result);
};

void Interpreter::advance() {
    this->pos += 1;

    if (this->pos > (int)this->text.length() - 1) {
        this->current_char = '\0';
    } else {
        this->current_char = this->text.at(this->pos);
    }
};

void Interpreter::skip_whitespace() {
    while (this->current_char == ' ')
        this->advance();
};

void Interpreter::eat(std::string token_type) {
    if (this->current_token->type == token_type) {
        this->current_token = this->get_next_token();
    } else {
        // TODO: raise error here
    }
};

std::string Interpreter::expr() {
    this->current_token = this->get_next_token();

    Token* left;
    Token* op;
    Token* right;

    std::string result = "";

    left = this->current_token;
    this->eat(T_INTEGER);

    op = this->current_token;
    if (op->type == T_PLUS)
        this->eat(T_PLUS);
    else
        this->eat(T_MINUS);

    right = this->current_token;
    this->eat(T_INTEGER);

    if (op->type == T_PLUS)
        result = std::to_string(std::stoi(left->value) + std::stoi(right->value));
    else
        result = std::to_string(std::stoi(left->value) - std::stoi(right->value));

    return result;
};
