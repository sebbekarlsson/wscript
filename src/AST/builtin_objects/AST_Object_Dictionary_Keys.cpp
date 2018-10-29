#include "../../includes/AST/builtin_objects/AST_Object_Dictionary_Keys.hpp"
#include "../../includes/AST/AST_Array.hpp"
#include "../../includes/typedefs.hpp"
#include <iostream>


AST_Object_Dictionary_Keys::AST_Object_Dictionary_Keys(std::string name, AST_Object* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
}

AST_Object_Dictionary_Keys::~AST_Object_Dictionary_Keys() {
    delete this->obj;
};

AST* AST_Object_Dictionary_Keys::call(std::vector<AST*> args, Interpreter* interpreter) {
    AST_Array* arr = new AST_Array(nullptr);

    std::map<std::string, anything> m = this->obj->get_private_scope()->variables;
    
    for(std::map<std::string, anything>::iterator it = m.begin(); it != m.end(); ++it)
        arr->items.push_back(it->first);

    return arr;
};
