#ifndef AST_FUNCTION_UBOUND_H
#define AST_FUNCTION_UBOUND_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_UBound: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_UBound(std::string name);
        ~AST_Function_UBound();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);
};
#endif
