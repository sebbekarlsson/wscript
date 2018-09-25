#include "../includes/AST/AST_UserDefinedFunctionCall.hpp"
#include "../includes/AST/AST_Var.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_UserDefinedFunctionCall::AST_UserDefinedFunctionCall(std::vector<AST*> args, std::string name) : AST_FunctionCall(args) {
    this->name = name;
};

AST_UserDefinedFunctionCall::~AST_UserDefinedFunctionCall() {};

AST* AST_UserDefinedFunctionCall::call(Interpreter* interpreter) {
    if (this->definition != nullptr)
        return this->definition->body;

    return new AST_NoOp();
};
