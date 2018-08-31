#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "Token.hpp"


class Interpreter {
    public:
        Interpreter(std::string text);

        std::string text;
        char current_char = '\0';

        int pos;

        Token* current_token;

        Token* get_next_token();

        int integer();

        void advance();
        void skip_whitespace();
        void eat(std::string token_type);

        std::string expr();
};
#endif
