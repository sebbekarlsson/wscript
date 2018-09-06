#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "Token.hpp"
#include "Lexer.hpp"
#include "AST.hpp"


class Interpreter {
    public:
        Interpreter(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);

        AST* factor();
        AST* term();
        AST* expr();
        AST* parse();
};
#endif
