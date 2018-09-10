#ifndef IF_H
#define IF_H
#include "AST.hpp"
#include "Comparison.hpp"


class If: public AST {
    public:
        If(Comparison* comp, AST* root);

        Comparison* comp;
        AST* root;
        
        bool value;
};
#endif
