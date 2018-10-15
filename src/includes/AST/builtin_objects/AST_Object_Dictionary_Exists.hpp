#ifndef AST_OBJECT_DICT_EXISTS_H
#define AST_OBJECT_DICT_EXISTS_H
#include "../AST_BuiltinFunctionDefinition.hpp"
#include "../AST_Object.hpp"
#include "../../Interpreter.hpp"


class AST_Object_Dictionary_Exists: public AST_BuiltinFunctionDefinition {
    public:
        AST_Object_Dictionary_Exists(std::string name, AST_Object* obj);
        ~AST_Object_Dictionary_Exists();

        AST* call(std::vector<AST*> args, Interpreter* interpreter);

        AST_Object* obj;
};
#endif
