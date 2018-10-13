#include "../includes/AST/AST_ArrayCall.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_ArrayCall::AST_ArrayCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_ArrayCall::~AST_ArrayCall() {};

AST* AST_ArrayCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        interpreter->error("Array expects 1 argument");

    anything type = interpreter->visit(this->args[0]);

    if (type.type() != typeid(int))
        interpreter->error("Array only accepts int arguments");

    return new AST_Array(nullptr);
};
