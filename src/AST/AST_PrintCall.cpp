#include "../includes/AST/AST_PrintCall.hpp"
#include "../includes/AST/AST_Var.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_PrintCall::AST_PrintCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_PrintCall::~AST_PrintCall() {};

AST* AST_PrintCall::call(Interpreter* interpreter) {
    if (this->args.size()) {
        for (
            std::vector<AST*>::iterator it = this->args.begin();
            it != this->args.end();
            ++it
        )
            std::cout << interpreter->visit((*it)) << std::endl;
    }

    return new AST_NoOp();
};
