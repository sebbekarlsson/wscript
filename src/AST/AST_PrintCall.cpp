#include "../includes/AST/AST_PrintCall.hpp"
#include "../includes/AST/AST_Var.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include <iostream>


AST_PrintCall::AST_PrintCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST* AST_PrintCall::call(std::vector<int> call_args) {
    if (call_args.size()) {
        for (
            std::vector<int>::iterator it = call_args.begin();
            it != call_args.end();
            ++it
        ) {
            std::cout << (*it) << std::endl;
        }
    }

    return new AST_NoOp();
};
