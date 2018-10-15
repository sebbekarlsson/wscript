#ifndef AST_UNARYOP_H
#define AST_UNARYOP_H
#include "AST.hpp"
#include "../Token.hpp"


class AST_UnaryOp: public AST {
    public:
        AST_UnaryOp(Token* op, AST* expr);
        ~AST_UnaryOp();

        Token* op;
        Token* token;

        AST* expr;
};
#endif
