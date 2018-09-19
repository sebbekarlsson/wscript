#ifndef AST_INTEGER_H
#define AST_INTEGER_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Integer: public AST {
    public:
        AST_Integer(Token* token);
        ~AST_Integer();

        Token* token;
};
#endif
