#include "../includes/AST/AST_If.hpp"


AST_If::AST_If(AST* comp, AST* root) {
    this->comp = comp;
    this->root = root;
    this->value = true;
}
