#include "../includes/AST/AST_VarDecl.hpp"


AST_VarDecl::AST_VarDecl(Token* token) {
    this->token = token;
    this->key = token->value;
}
