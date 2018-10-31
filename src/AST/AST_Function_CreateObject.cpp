#include "../includes/AST/AST_Function_CreateObject.hpp"
#include "../includes/AST/builtin_objects/AST_Object_Dictionary.hpp"
#include "../includes/AST/AST_ObjectCustom.hpp"
#include "../includes/AST/AST_Object.hpp"
#include "../includes/Interpreter.hpp"
#include "../includes/typedefs.hpp"
#include "../includes/DLClass.hpp"
#include <iostream>


AST_Function_CreateObject::AST_Function_CreateObject(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->expected_args.push_back(TokenType::String);
}

AST_Function_CreateObject::~AST_Function_CreateObject() {
};

AST* AST_Function_CreateObject::call(std::vector<AST*> args, Interpreter* interpreter) {
    anything type = interpreter->visit(args[0]);

    std::string obj_type = boost::get<std::string>(type);

    if (obj_type == "Scripting.Dictionary") {
        return new AST_Object_Dictionary(nullptr);
    } else {
        auto someType = new DLClass<AST_ObjectCustom>(obj_type);

        AST_ObjectCustom* cus = &(*someType->make_obj(0));

        delete someType;

        return cus;
    }
};
