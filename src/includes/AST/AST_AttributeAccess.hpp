#ifndef AST_ATTRIBUTE_ACCESS_H
#define AST_ATTRIBUTE_ACCESS_H
#include "AST.hpp"


class AST_AttributeAccess: public AST {
    public:
        AST_AttributeAccess(AST* left, AST* right);
        ~AST_AttributeAccess();

        AST* left;
        AST* right;
};
#endif
