#ifndef AST_FUNCTION_CREATEOBJECT_H
#define AST_FUNCTION_CREATEOBJECT_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_CreateObject: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_CreateObject(std::string name);
        ~AST_Function_CreateObject();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
