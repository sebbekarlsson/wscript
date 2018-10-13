#include "../../includes/AST/builtin_objects/AST_Object_Dictionary_Add.hpp"
#include "../../includes/typedefs.hpp"
#include <iostream>


AST_Object_Dictionary_Add::AST_Object_Dictionary_Add(std::string name, AST_Object* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
};

AST_Object_Dictionary_Add::~AST_Object_Dictionary_Add() {};

AST* AST_Object_Dictionary_Add::call(std::vector<AST*> args, Interpreter* interpreter) {
    if (args.size() < 2)
        interpreter->error("Add takes two arguments");

    anything x = interpreter->visit(args[0]);

    if (x.type() != typeid(std::string))
        interpreter->error("First argument in Add must be string");

    std::string _x = boost::get<std::string>(x);
    anything y = interpreter->visit(args[1]);

    this->obj->private_scope->set_variable(_x, y);

    return new AST_NoOp();
};
