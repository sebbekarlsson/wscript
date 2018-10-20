#include "../includes/AST/AST_AttributeAccess.hpp"


AST_AttributeAccess::AST_AttributeAccess(AST* left, AST* right) {
    this->left = left;
    this->right = right;
};


AST_AttributeAccess::~AST_AttributeAccess() {
    delete this->left;
    delete this->right;
};
