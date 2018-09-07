#ifndef ASSIGN_H
#define ASSIGN_H
#include "AST.hpp"
#include "Token.hpp"


class Assign: public AST {
    public:
        Assign(AST* left, Token* op, AST* right);

        Token* token;
        AST* left;
        Token* op;
        AST* right;
};
#endif
