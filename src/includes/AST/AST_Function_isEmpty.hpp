#ifndef AST_FUNCTION_ISEMPTY_H
#define AST_FUNCTION_ISEMPTY_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_isEmpty: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_isEmpty(std::string name);
        ~AST_Function_isEmpty();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);
};
#endif
