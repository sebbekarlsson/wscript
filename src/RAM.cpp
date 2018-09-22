#include "includes/RAM.hpp"


std::map<std::string, anything> RAM::variables;
std::vector<AST_FunctionDefinition*> RAM::function_definitions;

void RAM::set_variable(std::string key, anything value) {
    RAM::variables[key] = value;
};

void RAM::define_function(AST_FunctionDefinition* definition) {
    RAM::function_definitions.push_back(definition);
};

anything RAM::get_variable(std::string key) {
    if (RAM::variables.find(key) == RAM::variables.end())
        throw std::runtime_error("Trying to access undefined variable: `" + key + "`");

    return RAM::variables[key];
};

bool RAM::has_variable(std::string key) {
    return RAM::variables.find(key) != RAM::variables.end();
};

AST_FunctionDefinition* RAM::get_function_definition(std::string name) {
    for (std::vector<AST_FunctionDefinition*>::iterator it = RAM::function_definitions.begin(); it != RAM::function_definitions.end(); ++it) {
        if ((*it)->name == name)
            return (*it);
    }

    return nullptr;
};
