#include "../../includes/AST/builtin_objects/AST_Object_Dictionary_Items.hpp"
#include "../../includes/AST/AST_Array.hpp"
#include "../../includes/typedefs.hpp"
#include <iostream>


AST_Object_Dictionary_Items::AST_Object_Dictionary_Items(std::string name, AST_Object* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
}

AST_Object_Dictionary_Items::~AST_Object_Dictionary_Items() {};

AST* AST_Object_Dictionary_Items::call(std::vector<AST*> args, Interpreter* interpreter) {
    AST_Array* arr = new AST_Array(nullptr);

    std::map<std::string, anything> m = this->obj->get_private_scope()->variables;
    
    for(std::map<std::string, anything>::iterator it = m.begin(); it != m.end(); ++it)
        arr->items.push_back(it->second);

    return arr;
};
