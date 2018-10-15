#ifndef AST_VAR_H
#define AST_VAR_H
#include "AST.hpp"
#include "../Token.hpp"


class AST_Var: public AST {
    public:
        AST_Var(Token* token);
        ~AST_Var();

        Token* token;

        std::string value;
};
#endif
