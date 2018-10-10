#ifndef SCOPE_H
#define SCOPE_H
#include <string>
#include <map>
#include <vector>
#include "typedefs.hpp"
#include "AST/AST_FunctionDefinition.hpp"
#include "AST/AST_UserDefinedFunctionCall.hpp"
#include "AST/AST_BuiltinFunctionDefinition.hpp"
#include "AST/AST_Return.hpp"


class Scope {
    public:
        Scope(std::string name);

        void set_variable(std::string key, anything);
        void define_function(AST_FunctionDefinition* definition);
        void define_builtin_function(AST_BuiltinFunctionDefinition* udfc);
        void free_var(std::string key);

        anything get_variable(std::string key);

        bool has_variable(std::string key);

        AST_FunctionDefinition* get_function_definition(std::string name);
        AST_BuiltinFunctionDefinition* get_builtin_function(std::string name);

        AST_Return* return_node;

        std::string name;

        std::map<std::string, anything> variables;
        std::vector<AST_FunctionDefinition*> function_definitions;
        std::vector<AST_BuiltinFunctionDefinition*> builtin_functions;
};
#endif
