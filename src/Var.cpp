#include "includes/Var.hpp"


Var::Var(Token* token) {
    this->token = token;
    this->value = token->value;
};
