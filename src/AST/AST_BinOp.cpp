#include "../includes/AST/AST_BinOp.hpp"


AST_BinOp::AST_BinOp(AST* left, Token* op, AST* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
};

AST_BinOp::~AST_BinOp() {};
