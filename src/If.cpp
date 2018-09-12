#include "includes/If.hpp"


If::If(AST* comp, AST* root) {
    this->comp = comp;
    this->root = root;
    this->value = true;
}
