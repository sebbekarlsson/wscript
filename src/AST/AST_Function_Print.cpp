#include "../includes/AST/AST_Function_Print.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include "../includes/typedefs.hpp"
#include "../includes/cout.hpp"
#include <iostream>


AST_Function_Print::AST_Function_Print(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->unlimited_args = true;
}

AST_Function_Print::~AST_Function_Print() {
};

AST* AST_Function_Print::call(std::vector<AST*> args, Interpreter* interpreter) {
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
