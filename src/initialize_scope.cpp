#include "includes/initialize_scope.hpp"
#include "includes/AST/AST_Function_Split.hpp"
#include "includes/AST/AST_Function_UBound.hpp"
#include "includes/AST/AST_Function_isEmpty.hpp"
#include "includes/AST/AST_Function_CreateObject.hpp"
#include "includes/AST/AST_Function_Print.hpp"
#include "includes/AST/AST_Function_Array.hpp"


void initialize_scope(Scope* scope) {
    scope->define_builtin_function(new AST_Function_Split("split"));
    scope->define_builtin_function(new AST_Function_UBound("ubound"));
    scope->define_builtin_function(new AST_Function_isEmpty("isempty"));
    scope->define_builtin_function(new AST_Function_CreateObject("createobject"));
    scope->define_builtin_function(new AST_Function_Print("print"));
    scope->define_builtin_function(new AST_Function_Array("array"));
};
