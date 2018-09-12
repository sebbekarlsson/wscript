#include "../includes/AST/AST_Num.hpp"


AST_Num::AST_Num(Token* token) {
    this->token = token;
    this->value = std::stoi(token->value);
};
