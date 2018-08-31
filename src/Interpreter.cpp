#include "includes/TOKEN_TYPES.h"
#include "includes/Interpreter.hpp"
#include <ctype.h>
#include <iostream>
#include <sstream>


Interpreter::Interpreter(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_token = nullptr;
    this->current_char = this->text.at(this->pos);
};

/**
 * Collects the next token in the text
 *
 * @return Token*
 */
Token* Interpreter::get_next_token() {
    while (this->current_char != '\0') {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }

        std::stringstream ss;
        std::string s;
        ss << this->current_char;
        ss >> s;

        if (isdigit(this->current_char))
            return new Token(T_INTEGER, std::to_string(this->integer()));

        if (this->current_char == '+') {
            this->advance();
            return new Token(T_PLUS, s);
        }

        if (this->current_char == '-') {
            this->advance();
            return new Token(T_MINUS, s);
        }

        if (this->current_char == '*') {
            this->advance();
            return new Token(T_MULTIPLY, s);
        }

        if (this->current_char == '/') {
            this->advance();
            return new Token(T_DIVIDE, s);
        }

        throw std::runtime_error("Unexpected: `" + s + "`");
    }

    return new Token(T_EOF, "");
};

/**
 * Append single numbers into complete integers
 *
 * @return int
 */
int Interpreter::integer() {
    std::string result = "";

    while (this->current_char != '\0' && isdigit(this->current_char)) {
        result += this->current_char;
        this->advance();
    }

    return std::stoi(result);
};

/**
 * Tells the interpreter to go to the next character.
 */
void Interpreter::advance() {
    this->pos += 1;

    if (this->pos > (int)this->text.length() - 1) {
        this->current_char = '\0';
    } else {
        this->current_char = this->text.at(this->pos);
    }
};

/**
 * Tells the interpreter to go to the next character until the
 * current_char is not whitespace.
 */
void Interpreter::skip_whitespace() {
    while (this->current_char == ' ')
        this->advance();
};

/**
 * Takes an expected token_type as argument,
 * if the current_token->type is equal to that, it will
 * fetch the next token and assign it to this->current_token.
 *
 * If the token_type passed in is not equal to the current one, it will
 * throw an error.
 *
 * @param std::string token_type - the expected current token type.
 */
void Interpreter::eat(std::string token_type) {
    if (this->current_token->type == token_type) {
        this->current_token = this->get_next_token();
    } else {
        throw std::runtime_error("Unexpected token type: `" + token_type + "`");
    }
};

/**
 * executes the Interpretter::eats method with T_INTEGER
 * and returns the current_token->value that was before `eat` was executed.
 * 
 * @return std::string
 */
std::string Interpreter::term() {
    Token* token = this->current_token;
    this->eat(T_INTEGER);
    return token->value;
};

/**
 * Tells the interpreter to parse a mathematical expression
 *
 * @return std::string
 */
std::string Interpreter::expr() {
    this->current_token = this->get_next_token();

    Token* token = nullptr;

    std::string result = this->term();

    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS ||
        this->current_token->type == T_MULTIPLY ||
        this->current_token->type == T_DIVIDE
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
        } else if (token->type == T_DIVIDE) {
            this->eat(T_DIVIDE);
            result = std::to_string(std::stoi(result) / std::stoi(this->term()));
        }
    };

    return result;
};
