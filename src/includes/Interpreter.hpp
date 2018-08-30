#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "Token.hpp"


class Interpreter {
    public:
        Interpreter(std::string text);

        std::string text;
        int pos;
        Token* current_token;

        Token* get_next_token();

        void eat(std::string token_type);

        std::string expr();
};
#endif
