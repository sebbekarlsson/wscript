#include "../includes/AST/AST_FunctionDefinition.hpp"
#include "../includes/Scope.hpp"


AST_FunctionDefinition::AST_FunctionDefinition(std::string name, std::vector<Token*> args, AST_Compound* body) {
    this->name = name;
    this->args = args;
    this->body = body;
};
