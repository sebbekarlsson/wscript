#ifndef AST_WSCRIPT_ECHO_H
#define AST_WSCRIPT_ECHO_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include <iostream>
#include "../AST_NoOp.hpp"
#include "../../Interpreter.hpp"
#include "../../cout.hpp"


class AST_WScript_Echo: public AST_BuiltinFunctionDefinition {
    public:
        AST_WScript_Echo(std::string name);
        ~AST_WScript_Echo();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);
};
#endif
