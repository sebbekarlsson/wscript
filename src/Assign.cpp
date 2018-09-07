#include "includes/Assign.hpp"


Assign::Assign(AST* left, Token* op, AST* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
};
