#include "../../includes/AST/builtin_objects/AST_Object_Dictionary.hpp"


AST_Object_Dictionary::AST_Object_Dictionary(Token* token) : AST_Object(token) {
    this->token = token;
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Add("Add", this));
};

AST_Object_Dictionary::~AST_Object_Dictionary() {};
