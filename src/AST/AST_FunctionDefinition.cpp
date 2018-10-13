#include "../includes/AST/AST_FunctionDefinition.hpp"
#include "../includes/Scope.hpp"
#include "../includes/memory_utils.hpp"


AST_FunctionDefinition::AST_FunctionDefinition(std::string name, std::vector<Token*> args, AST_Compound* body) {
    this->name = name;
    this->args = args;
    this->body = body;
};

AST_FunctionDefinition::~AST_FunctionDefinition() {
    if (this->body != nullptr)
        delete this->body;

    this->args.clear();
    free_vector(this->args);
};
