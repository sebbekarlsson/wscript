#ifndef AST_OBJECT_DICT_ITEMS_H
#define AST_OBJECT_DICT_ITEMS_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include "../AST_Object.hpp"
#include "../../Interpreter.hpp"
#include <map>


class AST_Object_Dictionary_Items: public AST_BuiltinFunctionDefinition {
    public:
        AST_Object_Dictionary_Items(std::string name, AST_Object* obj);
        ~AST_Object_Dictionary_Items();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
