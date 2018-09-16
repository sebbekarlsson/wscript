#include "../includes/AST/AST_Str.hpp"


AST_Str::AST_Str(Token* token) {
    this->token = token;
    this->value = token->value;
};

AST_Str::~AST_Str() {};
