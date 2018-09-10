#include "includes/If.hpp"


If::If(Comparison* comp, AST* root) {
    this->comp = comp;
    this->root = root;
    this->value = true;
}
