#ifndef AST_NUM_H
#define AST_NUM_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Num: public AST {
    public:
        AST_Num(Token* token);

        Token* token;
        int value;
};
#endif
