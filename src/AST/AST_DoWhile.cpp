#include "../includes/AST/AST_DoWhile.hpp"


AST_DoWhile::AST_DoWhile(AST* expr, AST_Compound* body) {
    this->expr = expr;
    this->body = body;
};

AST_DoWhile::~AST_DoWhile() {};
