#include "includes/UnaryOp.hpp"


UnaryOp::UnaryOp(Token* op, AST* expr) {
    this->op = op;
    this->token = op;
    this->expr = expr;
}
