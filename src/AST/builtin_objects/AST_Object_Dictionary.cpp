#include "../../includes/AST/builtin_objects/AST_Object_Dictionary.hpp"
#include "../../includes/Scope.hpp"


AST_Object_Dictionary::AST_Object_Dictionary(Token* token) : AST_Object(token) {
    this->token = token;
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Add("Add", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Exists("Exists", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Keys("Keys", this));
};

AST_Object_Dictionary::~AST_Object_Dictionary() {};
