#ifndef AST_ASSIGN_H
#define AST_ASSIGN_H
#include "AST.hpp"
#include "../Token.hpp"
#include "../AST/AST_Var.hpp"


class AST_Assign: public AST {
    public:
        AST_Assign(AST_Var* left, Token* op, AST* right);
        ~AST_Assign();

        Token* token;
        Token* op;
        
        AST* right;
        
        AST_Var* left;
};
#endif
