#ifndef AST_ARRAY_H
#define AST_ARRAY_H
#include "AST.hpp"
#include "../Token.hpp"
#include "../typedefs.hpp"
#include <vector>


class AST_Array: public AST {
    public:
        AST_Array(Token* token);
        ~AST_Array();

        Token* token;

        std::vector<anything> items;
};
#endif
