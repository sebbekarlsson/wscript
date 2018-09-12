#ifndef IF_H
#define IF_H
#include "AST.hpp"


class If: public AST {
    public:
        If(AST* comp, AST* root);

        AST* comp;
        AST* root;
        
        bool value;
};
#endif
