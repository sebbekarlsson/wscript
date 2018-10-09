#ifndef AST_OBJECT_DICT_ADD_H
#define AST_OBJECT_DICT_ADD_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include "../AST_Object.hpp"
#include "../../Interpreter.hpp"


class AST_Object_Dictionary_Add: public AST_BuiltinFunctionDefinition {
    public:
        AST_Object_Dictionary_Add(std::string name, AST_Object* obj);
        ~AST_Object_Dictionary_Add();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
