#ifndef AST_OBJECT_DICT_KEYS_H
#define AST_OBJECT_DICT_KEYS_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include "../AST_Object.hpp"
#include "../../Interpreter.hpp"
#include <map>


class AST_Object_Dictionary_Keys: public AST_BuiltinFunctionDefinition {
    public:
        AST_Object_Dictionary_Keys(std::string name, AST_Object* obj);
        ~AST_Object_Dictionary_Keys();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
