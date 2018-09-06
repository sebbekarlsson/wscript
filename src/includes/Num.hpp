#ifndef NUM_H
#define NUM_H
#include "AST.hpp"
#include "Token.hpp"
#include <string>


class Num: public AST {
    public:
        Num(Token* token);

        Token* token;
        std::string value;
};
#endif
