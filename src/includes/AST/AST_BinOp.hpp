#ifndef AST_BINOP_H
#define AST_BINOP_H
#include "AST.hpp"
#include "../Token.hpp"


class AST_BinOp: public AST {
    public:
        AST_BinOp(AST* left, Token* op, AST* right);
        ~AST_BinOp();

        Token* token;
        Token* op;
        
        AST* left;
        AST* right;
};
#endif
