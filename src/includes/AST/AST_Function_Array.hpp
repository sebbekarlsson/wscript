#ifndef AST_FUNCTION_ARRAY_H
#define AST_FUNCTION_ARRAY_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_Array: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_Array(std::string name);
        ~AST_Function_Array();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
