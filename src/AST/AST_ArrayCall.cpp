#include "../includes/AST/AST_ArrayCall.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_ArrayCall::AST_ArrayCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_ArrayCall::~AST_ArrayCall() {};

AST* AST_ArrayCall::call(Interpreter* interpreter) {
    AST_Array* arr = new AST_Array(nullptr);

    for (std::vector<AST*>::iterator it = this->args.begin(); it != this->args.end(); ++it) {
        arr->items.push_back(interpreter->visit((*it)));
    }

    return arr;
};
