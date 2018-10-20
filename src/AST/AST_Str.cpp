#include "../includes/AST/AST_Str.hpp"


AST_Str::AST_Str(Token* token) {
    this->token = token;
};

AST_Str::~AST_Str() {
    delete this->token;
};
