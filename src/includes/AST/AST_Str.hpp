#ifndef AST_STR_H
#define AST_STR_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Str: public AST {
    public:
        AST_Str(Token* token);
        ~AST_Str();

        Token* token;
};
#endif
