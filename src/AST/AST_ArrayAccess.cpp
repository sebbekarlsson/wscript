#include "../includes/AST/AST_ArrayAccess.hpp"


AST_ArrayAccess::AST_ArrayAccess(AST_Array* array_node, std::vector<AST*> args) {
    this->array_node = array_node;
    this->args = args;
};


AST_ArrayAccess::~AST_ArrayAccess() {};
