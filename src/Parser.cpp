#include "includes/Parser.hpp"
#include "includes/Num.hpp"
#include "includes/BinOp.hpp"
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

Parser::Parser(Lexer* lexer) {
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
void Parser::eat(std::string token_type) {
    if (this->current_token->type == token_type) {
        this->current_token = this->lexer->get_next_token();
    } else {
        throw std::runtime_error("Unexpected token type: `" + token_type + "`");
    }
};

/**
 * executes the Parser::eats method with T_INTEGER
 * and returns the current_token->value that was before `eat` was executed.
 * factor: INTEGER
 * 
 * @return std::string
 */
AST* Parser::factor() {
    Token* token = this->current_token;

    if (token->type == T_INTEGER) {
        this->eat(T_INTEGER);
        return new Num(token);
    }

    if (token->type == T_LPAREN) {
        this->eat(T_LPAREN);
        BinOp* node = (BinOp*)this->expr();
        this->eat(T_RPAREN);
        return node;
    }

    return nullptr;
};

/**
 * Handles multiplication and division
 * term : factor ((MUL | DIV) factor)*
 *
 * @return std::string
 */
AST* Parser::term() {
    Token* token = nullptr;

    // we actually dont know if "this->factor()" will
    // return a BinOp* or a Num*.
    BinOp* node = (BinOp*)this->factor();

    while (
        this->current_token->type == T_MULTIPLY ||
        this->current_token->type == T_DIVIDE
    ) {
        token = this->current_token;

        if (token->type == T_MULTIPLY) {
            this->eat(T_MULTIPLY);
        } else if (token->type == T_DIVIDE) {
            this->eat(T_DIVIDE);
        }

        // we actually dont know if "this->factor()" will
        // return a BinOp* or a Num*.
        node = new BinOp(node, token, this->factor());
    }

    return node;
};

/**
 * Tells the interpreter to parse a mathematical expression,
 * arithmetic expression parsing.
 *
 * @return std::string
 */
AST* Parser::expr() {
    Token* token = nullptr;

    BinOp* node = (BinOp*)this->term();

    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS
    ) {
        token = this->current_token;

        if (token->type == T_PLUS) {
            this->eat(T_PLUS);
        } else if (token->type == T_MINUS) {
            this->eat(T_MINUS);
        }

        node = new BinOp(node, token, this->term());
    };

    return node;
};

AST* Parser::parse() {
    return this->expr();
};
