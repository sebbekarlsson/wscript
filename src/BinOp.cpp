#include "includes/BinOp.hpp"


BinOp::BinOp(Token* left, Token* op, Token* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
}
