#ifndef LEXER_H
#define LEXER_H
#include <string>
#include "Token.hpp"


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;

        char current_char = '\0';

        int pos;

        Token* get_next_token();

        int integer();

        void advance();
        void skip_whitespace();
};
#endif
