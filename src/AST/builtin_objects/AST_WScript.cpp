#include "../../includes/AST/builtin_objects/AST_WScript.hpp"
#include "../../includes/Scope.hpp"


AST_WScript::AST_WScript() : AST_Object() {
    this->private_scope->define_builtin_function(new AST_WScript_Echo("Echo"));
};

AST_WScript::~AST_WScript() {};
