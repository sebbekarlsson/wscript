#include "includes/Assign.hpp"


Assign::Assign(Var* left, Token* op, AST* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
};
