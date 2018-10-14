#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include "Token.hpp"
#include "TokenType.hpp"


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;

        char current_char = '\0';

        int pos;
        int line;

        Token* latest_token;

        Token* get_next_token();
        Token* _get_next_token();
        Token* number();
        Token* str();
        Token* _id();
        
        char peek();
        char peek_next(int start);

        void advance();
        void skip_whitespace();
        void skip_comment();
        void error(std::string message);
};
#endif
