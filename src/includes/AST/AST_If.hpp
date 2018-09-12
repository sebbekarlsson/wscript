#ifndef AST_IF_H
#define AST_IF_H
#include "AST.hpp"


class AST_If: public AST {
    public:
        AST_If(AST* comp, AST* root);

        AST* comp;
        AST* root;
        
        bool value;
};
#endif
