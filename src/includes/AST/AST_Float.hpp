#ifndef AST_FLOAT_H
#define AST_FLOAT_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Float: public AST {
    public:
        AST_Float(Token* token);
        ~AST_Float();

        Token* token;
};
#endif
