#ifndef AST_VARDECL_H
#define AST_VARDECL_H
#include "AST.hpp"
#include "../Token.hpp"
#include <vector>


class AST_VarDecl: public AST {
    public:
        AST_VarDecl(std::vector<Token*> tokens);
        ~AST_VarDecl();

        std::vector<Token*> tokens;
};
#endif
