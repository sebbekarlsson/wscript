#include "includes/Interpreter.hpp"
#include <ctype.h>
#include <iostream>
#include <sstream>


extern std::string T_INTEGER;
extern std::string T_PLUS;
extern std::string T_MINUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_LPAREN;
extern std::string T_RPAREN;

Interpreter::Interpreter(Lexer* lexer) {
    this->lexer = lexer;
    this->current_token = this->lexer->get_next_token();
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
        this->current_token = this->lexer->get_next_token();
    } else {
        throw std::runtime_error("Unexpected token type: `" + token_type + "`");
    }
};

/**
 * executes the Interpreter::eats method with T_INTEGER
 * and returns the current_token->value that was before `eat` was executed.
 * factor: INTEGER
 * 
 * @return std::string
 */
std::string Interpreter::factor() {
    Token* token = this->current_token;

    if (token->type == T_INTEGER) {
        this->eat(T_INTEGER);
        return token->value;
    }

    if (token->type == T_LPAREN) {
        std::string result = "";

        this->eat(T_LPAREN);
        result = this->expr();
        this->eat(T_RPAREN);

        return result;
    }
};

/**
 * Handles multiplication and division
 * term : factor ((MUL | DIV) factor)*
 *
 * @return std::string
 */
std::string Interpreter::term() {
    Token* token = nullptr;
    
    std::string result = this->factor();

    while (
        this->current_token->type == T_MULTIPLY ||
        this->current_token->type == T_DIVIDE
    ) {
        token = this->current_token;

        if (token->type == T_MULTIPLY) {
            this->eat(T_MULTIPLY);
            result = std::to_string(std::stoi(result) * std::stoi(this->factor()));
        } else if (token->type == T_DIVIDE) {
            this->eat(T_DIVIDE);
            result = std::to_string(std::stoi(result) / std::stoi(this->factor()));
        }
    }

    return result;
};

/**
 * Tells the interpreter to parse a mathematical expression,
 * arithmetic expression parsing.
 *
 * @return std::string
 */
std::string Interpreter::expr() {
    Token* token = nullptr;

    std::string result = this->term();

    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS
    ) {
        token = this->current_token;

        if (token->type == T_PLUS) {
            this->eat(T_PLUS);
            result = std::to_string(std::stoi(result) + std::stoi(this->term()));
        } else if (token->type == T_MINUS) {
            this->eat(T_MINUS);
            result = std::to_string(std::stoi(result) - std::stoi(this->term()));
        }
    };

    return result;
};
