#include "includes/Comparison.hpp"


Comparison::Comparison(AST* left, Token* token, AST* right) {
    this->left = left;
    this->token = token;
    this->right = right;
    this->value = true;
}
