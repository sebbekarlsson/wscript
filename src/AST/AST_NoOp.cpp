#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Scope.hpp"


AST_NoOp::AST_NoOp() {
    delete this->private_scope;
    this->private_scope = nullptr;
};

AST_NoOp::~AST_NoOp() {};
