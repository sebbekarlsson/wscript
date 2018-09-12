#include "includes/PrintCall.hpp"
#include "includes/Var.hpp"
#include "includes/NoOp.hpp"
#include <iostream>


PrintCall::PrintCall(std::vector<AST*> args) : FunctionCall(args) {};

AST* PrintCall::call(std::vector<int> call_args) {
    if (call_args.size()) {
        for (
            std::vector<int>::iterator it = call_args.begin();
            it != call_args.end();
            ++it
        ) {
            std::cout << (*it) << std::endl;
        }
    }

    return new NoOp();
};
