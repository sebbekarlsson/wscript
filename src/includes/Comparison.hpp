#ifndef COMPARISON_H
#define COMPARISON_H
#include "AST.hpp"
#include "Token.hpp"


class Comparison: public AST {
    public:
        Comparison(AST* left, Token* token, AST* right);

        AST* left;
        Token* token;
        AST* right;
        
        bool value;
};
#endif
