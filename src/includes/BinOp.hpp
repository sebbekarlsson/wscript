#ifndef BINOP_H
#define BINOP_H
#include "AST.hpp"
#include "Token.hpp"


class BinOp: public AST {
    public:
        BinOp(Token* left, Token* op, Token* right);

        Token* token;
        Token* left;
        Token* op;
        Token* right;
};
#endif
