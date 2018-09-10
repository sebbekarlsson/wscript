#include "includes/VarDecl.hpp"


VarDecl::VarDecl(Token* token) {
    this->token = token;
    this->key = token->value;
}
