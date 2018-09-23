#include "../includes/AST/AST.hpp"
#include "../includes/Scope.hpp"


extern Scope* global_scope;

AST::AST() {}

Scope* AST::get_scope() {
    if (this->scope == nullptr)
        return global_scope;

    return this->scope;
};
