#include "../includes/AST/AST_Var.hpp"


AST_Var::AST_Var(Token* token) {
    this->token = token;
    this->value = token->value;
};


AST_Var::~AST_Var() {};
