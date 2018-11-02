#include "../../includes/AST/builtin_objects/AST_Object_Dictionary.hpp"
#include "../../includes/Scope.hpp"


AST_Object_Dictionary::AST_Object_Dictionary(Token* token) : AST_Object(token) {
    this->token = token;
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Add("add", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Exists("exists", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Keys("keys", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_Items("items", this));
    this->private_scope->define_builtin_function(new AST_Object_Dictionary_RemoveAll("removeall", this));
};

AST_Object_Dictionary::~AST_Object_Dictionary() {};
