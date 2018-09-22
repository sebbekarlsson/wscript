#include "../includes/AST/AST_UserDefinedFunctionCall.hpp"
#include "../includes/AST/AST_Var.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_UserDefinedFunctionCall::AST_UserDefinedFunctionCall(std::vector<AST*> args, AST_FunctionDefinition* definition) : AST_FunctionCall(args) {
    this->definition = definition;
};

AST_UserDefinedFunctionCall::~AST_UserDefinedFunctionCall() {};

AST* AST_UserDefinedFunctionCall::call(Interpreter* interpreter) {
    return this->definition->body;
};
