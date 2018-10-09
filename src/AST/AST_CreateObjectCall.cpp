#include "../includes/AST/AST_CreateObjectCall.hpp"
#include "../includes/AST/builtin_objects/AST_Object_Dictionary.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_CreateObjectCall::AST_CreateObjectCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_CreateObjectCall::~AST_CreateObjectCall() {};

AST* AST_CreateObjectCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        interpreter->error("CreateObject expects 1 argument");

    anything type = interpreter->visit(this->args[0]);

    if (type.type() != typeid(std::string))
        interpreter->error("CreateObject only accepts string arguments");

    std::string obj_type = boost::get<std::string>(type);

    if (obj_type == "Scripting.Dictionary")
        return new AST_Object_Dictionary(nullptr);
    else
        interpreter->error("Unknown object type: " + obj_type);
};
