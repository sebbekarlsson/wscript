#include "../../includes/AST/builtin_objects/AST_Object_Dictionary_Exists.hpp"
#include "../../includes/AST/AST_Integer.hpp"
#include "../../includes/typedefs.hpp"
#include <iostream>


AST_Object_Dictionary_Exists::AST_Object_Dictionary_Exists(std::string name, AST_Object* obj) : AST_BuiltinFunctionDefinition(name) {
    this->obj = obj;
    this->expected_args.push_back(TokenType::String);
}

AST_Object_Dictionary_Exists::~AST_Object_Dictionary_Exists() {};

AST* AST_Object_Dictionary_Exists::call(std::vector<AST*> args, Interpreter* interpreter) {
    anything x = interpreter->visit(args[0]);
    int _exists = 0;

    if (x.type() != typeid(std::string))
        interpreter->error("First argument in Exists must be string");

    std::string key = boost::get<std::string>(x);

    if (this->obj->get_private_scope()->variables.find(key) != this->obj->get_private_scope()->variables.end())
        _exists = 1;

    // TODO: return AST_Boolean
    return new AST_Integer(new Token(TokenType::Integer, std::to_string(_exists)));
};
