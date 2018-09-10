#ifndef VARDECL_H
#define VARDECL_H
#include "AST.hpp"
#include "Token.hpp"


class VarDecl: public AST {
    public:
        VarDecl(Token* token);

        Token* token;
        std::string key;
};
#endif
