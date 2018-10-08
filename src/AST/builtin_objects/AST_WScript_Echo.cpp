#include "../../includes/AST/builtin_objects/AST_WScript_Echo.hpp"


AST_WScript_Echo::AST_WScript_Echo(std::string name) : AST_BuiltinFunctionDefinition(name) {};

AST_WScript_Echo::~AST_WScript_Echo() {};

AST* AST_WScript_Echo::call(std::vector<AST*> args, Interpreter* interpreter) {
    if (args.size()) {
        for (
                std::vector<AST*>::iterator it = args.begin();
                it != args.end();
                ++it
            )
            std::cout << interpreter->visit((*it)) << std::endl;
    }

    return new AST_NoOp();
};
