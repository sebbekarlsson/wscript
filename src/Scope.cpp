#include "includes/Scope.hpp"


Scope::Scope(std::string name) {
    this->name = name;
    this->value = 0;
};

Scope::~Scope() {
    this->variables.clear();
    this->function_definitions.clear();
    this->builtin_functions.clear();
    this->name = "";
    this->value = nullptr;
};

void Scope::set_variable(std::string key, anything value) {
    this->variables[key] = value;
};

void Scope::define_function(AST_FunctionDefinition* definition) {
    this->function_definitions.push_back(definition);
};

void Scope::define_builtin_function(AST_BuiltinFunctionDefinition* udfc) {
    this->builtin_functions.push_back(udfc);
};

void Scope::free_var(std::string key) {
    this->variables.erase(key);
};

anything Scope::get_variable(std::string key) {
    if (this->variables.find(key) == this->variables.end())
        throw std::runtime_error("Trying to access undefined variable: `" + key + "`");

    return this->variables[key];
};

bool Scope::has_variable(std::string key) {
    return this->variables.find(key) != this->variables.end();
};

AST_FunctionDefinition* Scope::get_function_definition(std::string name) {
    for (std::vector<AST_FunctionDefinition*>::iterator it = this->function_definitions.begin(); it != this->function_definitions.end(); ++it)
        if ((*it)->name == name)
            return (*it);

    return nullptr;
};

AST_BuiltinFunctionDefinition* Scope::get_builtin_function(std::string name) {
    for (std::vector<AST_BuiltinFunctionDefinition*>::iterator it = this->builtin_functions.begin(); it != this->builtin_functions.end(); ++it) {
        if ((*it)->name == name)
            return (*it);}

    return nullptr;
};
