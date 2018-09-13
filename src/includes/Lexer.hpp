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
        Token* number();
        Token* _id();
        
        char peek();

        void advance();
        void skip_whitespace();
        void skip_comment();
        void error(std::string message);
};
#endif
