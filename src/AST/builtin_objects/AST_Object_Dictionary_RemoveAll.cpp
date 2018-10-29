#include "../../includes/AST/builtin_objects/AST_Object_Dictionary_RemoveAll.hpp"
#include "../../includes/typedefs.hpp"
#include <iostream>


AST_Object_Dictionary_RemoveAll::AST_Object_Dictionary_RemoveAll(std::string name, AST_Object* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
};

AST_Object_Dictionary_RemoveAll::~AST_Object_Dictionary_RemoveAll() {};

AST* AST_Object_Dictionary_RemoveAll::call(std::vector<AST*> args, Interpreter* interpreter) {
    this->obj->get_private_scope()->variables.clear();

    return new AST_NoOp();
};
