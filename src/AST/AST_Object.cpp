#include "../includes/AST/AST_Object.hpp"


AST_Object::AST_Object(Token* token) : AST() {
    this->token = token;
};

AST_Object::~AST_Object() {};
