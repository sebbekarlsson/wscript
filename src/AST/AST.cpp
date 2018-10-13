#include "../includes/AST/AST.hpp"
#include "../includes/Scope.hpp"


extern Scope* global_scope;

AST::AST() {
    this->private_scope = new Scope("AST_NODE"); // TODO: maybe not all nodes -
    // should have a private scope? ...
}

Scope* AST::get_scope() {
    if (this->scope == nullptr)
        return global_scope;

    return this->scope;
};

Scope* AST::get_private_scope() {
    return this->private_scope;
};

Scope* AST::get_parent_scope() {
    if (this->parent_scope == nullptr)
        return global_scope;

    return this->parent_scope;
};
