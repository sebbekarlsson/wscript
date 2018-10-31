#ifndef AST_FUNCTION_PRINT_H
#define AST_FUNCTION_PRINT_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_Print: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_Print(std::string name);
        ~AST_Function_Print();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
