#ifndef AST_RETURN_H
#define AST_RETURN_H
#include "AST.hpp"
#include "../Token.hpp"
#include <string>


class AST_Return: public AST {
    public:
        AST_Return(AST* value);
        ~AST_Return();

        AST* value;
};
#endif
