#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Token.hpp"


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;

        char current_char = '\0';

        int pos;
        int line;

        Token* get_next_token();

        float number();

        char peek();

        Token* _id();

        void advance();
        void skip_whitespace();
        void skip_comment();
        void error(std::string message);
};
#endif
