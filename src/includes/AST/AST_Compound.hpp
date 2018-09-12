#ifndef AST_COMPOUND_H
#define AST_COMPOUND_H
#include "AST.hpp"
#include "../Token.hpp"
#include <vector>


class AST_Compound: public AST {
    public:
        AST_Compound();

        std::vector<AST*> children;
};
#endif
