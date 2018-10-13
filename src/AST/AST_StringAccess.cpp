#include "../includes/AST/AST_StringAccess.hpp"


AST_StringAccess::AST_StringAccess(std::string value, std::vector<AST*> args) {
    this->value = value;
    this->args = args;
};


AST_StringAccess::~AST_StringAccess() {};
