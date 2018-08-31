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

        if (this->current_char == '*') {
            this->advance();
            return new Token(T_MULTIPLY, "*");
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

std::string Interpreter::term() {
    Token* token = this->current_token;
    this->eat(T_INTEGER);
    return token->value;
};

std::string Interpreter::expr() {
    this->current_token = this->get_next_token();

    Token* token = nullptr;

    std::string result = this->term();

    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS ||
        this->current_token->type == T_MULTIPLY
    ) {
        token = this->current_token;

        if (token->type == T_PLUS) {
            this->eat(T_PLUS);
            result = std::to_string(std::stoi(result) + std::stoi(this->term()));
        } else if (token->type == T_MINUS) {
            this->eat(T_MINUS);
            result = std::to_string(std::stoi(result) - std::stoi(this->term()));
        } else if (token->type == T_MULTIPLY) {
            this->eat(T_MULTIPLY);
            result = std::to_string(std::stoi(result) * std::stoi(this->term()));
        }
    };

    return result;
};
