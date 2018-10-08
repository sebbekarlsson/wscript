#include "../includes/AST/AST_Return.hpp"


AST_Return::AST_Return(AST* value) {
    this->value = value;
};

AST_Return::~AST_Return() {};
