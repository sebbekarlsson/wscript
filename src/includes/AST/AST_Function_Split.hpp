#ifndef AST_FUNCTION_SPLIT_H
#define AST_FUNCTION_SPLIT_H
#include "AST_BuiltinFunctionDefinition.hpp"
#include "../Interpreter.hpp"
#include <map>


class AST_Function_Split: public AST_BuiltinFunctionDefinition {
    public:
        AST_Function_Split(std::string name);
        ~AST_Function_Split();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
