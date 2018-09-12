#include "../includes/AST/AST_FunctionCall.hpp"


AST_FunctionCall::AST_FunctionCall(std::vector<AST*> args) {
    this->args = args;
};
