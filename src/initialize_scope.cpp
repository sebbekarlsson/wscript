#include "includes/initialize_scope.hpp"
#include "includes/AST/AST_Function_Split.hpp"
#include "includes/AST/AST_Function_UBound.hpp"
#include "includes/AST/AST_Function_isEmpty.hpp"
#include "includes/AST/AST_Function_CreateObject.hpp"
#include "includes/AST/AST_Function_Print.hpp"
#include "includes/AST/AST_Function_Array.hpp"


void initialize_scope(Scope* scope) {
    scope->define_builtin_function(new AST_Function_Split("Split"));
    scope->define_builtin_function(new AST_Function_UBound("UBound"));
    scope->define_builtin_function(new AST_Function_isEmpty("isEmpty"));
    scope->define_builtin_function(new AST_Function_CreateObject("CreateObject"));
    scope->define_builtin_function(new AST_Function_Print("print"));
    scope->define_builtin_function(new AST_Function_Array("Array"));
};
