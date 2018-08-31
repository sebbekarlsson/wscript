#ifndef LEXER_H
#define LEXER_H
#include <string>


class Lexer {
    public:
        Lexer(std::string text);

        std::string text;

        char current_char = '\0';

        int pos;
};
#endif
