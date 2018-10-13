#include "../includes/AST/AST_PrintCall.hpp"
#include "../includes/AST/AST_Var.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_PrintCall::AST_PrintCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_PrintCall::~AST_PrintCall() {};

AST* AST_PrintCall::call(Interpreter* interpreter) {
    if (args.size()) {
        for (
                std::vector<AST*>::iterator it = args.begin();
                it != args.end();
                ++it
            ) {

            anything x = interpreter->visit((*it));
            coutprint(x);
        }
    }

    AST_NoOp* noop = new AST_NoOp();
    return noop;
};
