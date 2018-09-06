#include "includes/BinOp.hpp"


BinOp::BinOp(AST* left, Token* op, AST* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
}
