#include "../includes/AST/AST_Assign.hpp"


AST_Assign::AST_Assign(AST_Var* left, Token* op, AST* right) {
    this->left = left;
    this->op = op;
    this->token = this->op;
    this->right = right;
};
