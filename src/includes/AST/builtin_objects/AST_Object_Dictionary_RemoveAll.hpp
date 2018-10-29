#ifndef AST_OBJECT_DICT_REMOVE_ALL_H
#define AST_OBJECT_DICT_REMOVE_ALL_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include "../AST_Object.hpp"
#include "../../Interpreter.hpp"


class AST_Object_Dictionary_RemoveAll: public AST_BuiltinFunctionDefinition {
    public:
        AST_Object_Dictionary_RemoveAll(std::string name, AST_Object* obj);
        ~AST_Object_Dictionary_RemoveAll();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
