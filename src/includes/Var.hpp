#ifndef VAR_H
#define VAR_H
#include "AST.hpp"
#include "Token.hpp"


class Var: public AST {
    public:
        Var(Token* token);

        Token* token;
        std::string value;
};
#endif
