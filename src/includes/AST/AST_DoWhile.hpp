#ifndef AST_DO_WHILE_H
#define AST_DO_WHILE_H
#include "AST.hpp"
#include "AST_Compound.hpp"


class AST_DoWhile: public AST {
    public:
        AST_DoWhile(AST* expr, AST_Compound* body);
        ~AST_DoWhile();

        AST* expr;
        AST_Compound* body;
};
#endif
