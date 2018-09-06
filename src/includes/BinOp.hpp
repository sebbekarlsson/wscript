#ifndef BINOP_H
#define BINOP_H
#include "AST.hpp"
#include "Token.hpp"


class BinOp: public AST {
    public:
        BinOp(AST* left, Token* op, AST* right);

        Token* token;
        AST* left;
        Token* op;
        AST* right;
};
#endif
