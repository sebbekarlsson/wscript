#ifndef PARSER_H
#define PARSER_H
#include "Token.hpp"
#include "Lexer.hpp"
#include "AST.hpp"


class Parser {
    public:
        Parser(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);

        AST* factor();
        AST* term();
        AST* expr();
        AST* parse();
};
#endif
