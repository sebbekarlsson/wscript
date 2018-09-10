#ifndef ASSIGN_H
#define ASSIGN_H
#include "AST.hpp"
#include "Token.hpp"
#include "Var.hpp"


class Assign: public AST {
    public:
        Assign(Var* left, Token* op, AST* right);

        Token* token;
        Var* left;
        Token* op;
        AST* right;
};
#endif
