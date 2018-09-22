#ifndef RAMZ_H
#define RAMZ_H
#include <string>
#include <map>
#include <vector>
#include "typedefs.hpp"
#include "AST/AST_FunctionDefinition.hpp"


class RAM {
    public:
        static void set_variable(std::string key, anything);
        static void define_function(AST_FunctionDefinition* definition);

        static anything get_variable(std::string key);

        static bool has_variable(std::string key);

        static AST_FunctionDefinition* get_function_definition(std::string name);

    private:
        static std::map<std::string, anything> variables;

        static std::vector<AST_FunctionDefinition*> function_definitions;
};
#endif
