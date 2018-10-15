#ifndef AST_ARRAY_ACCESS_H
#define AST_ARRAY_ACCESS_H
#include "AST_Array.hpp"
#include <vector>


class AST_ArrayAccess: public AST {
    public:
        AST_ArrayAccess(AST_Array* array_node, std::vector<AST*> args);
        ~AST_ArrayAccess();

        AST_Array* array_node;

        std::vector<AST*> args;
};
#endif
