#include "../includes/AST/AST_UnaryOp.hpp"


AST_UnaryOp::AST_UnaryOp(Token* op, AST* expr) {
    this->op = op;
    this->token = op;
    this->expr = expr;
}
