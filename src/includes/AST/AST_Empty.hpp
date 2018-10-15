#ifndef AST_EMPTY_H
#define AST_EMPTY_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Empty: public AST {
    public:
        AST_Empty(Token* token);
        ~AST_Empty();

        Token* token;
};
#endif
