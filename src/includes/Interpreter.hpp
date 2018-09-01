#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "Token.hpp"
#include "Lexer.hpp"


class Interpreter {
    public:
        Interpreter(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);

        std::string factor();
        std::string term();
        std::string expr();
};
#endif
