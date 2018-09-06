#ifndef UNARYOP_H
#define UNARYOP_H
#include "AST.hpp"
#include "Token.hpp"


class UnaryOp: public AST {
    public:
        UnaryOp(Token* op, AST* expr);

        Token* op;
        Token* token;
        AST* expr;
};
#endif
