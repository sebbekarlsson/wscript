#ifndef AST_VARDECL_H
#define AST_VARDECL_H
#include "AST.hpp"
#include "../Token.hpp"


class AST_VarDecl: public AST {
    public:
        AST_VarDecl(Token* token);
        ~AST_VarDecl();

        Token* token;
        std::string key;
};
#endif
