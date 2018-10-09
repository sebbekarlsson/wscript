#ifndef AST_OBJECT_H
#define AST_OBJECT_H
#include "AST.hpp"
#include "../Token.hpp"


class AST_Object: public AST {
    public:
        AST_Object(Token* token);
        ~AST_Object();

        Token* token;
};
#endif
