#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include "TokenType.hpp"


class Token {
    public:
        Token(TokenType type, std::string value);

        TokenType type;
        std::string value;

        std::string get_string();

        int get_integer();

        float get_float();
};
#endif
