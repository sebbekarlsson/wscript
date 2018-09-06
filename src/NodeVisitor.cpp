#include "includes/NodeVisitor.hpp"


std::string NodeVisitor::visit(AST* node) {
    // if (node->type == BinOp) {
    //     return this-visit_BinOp(node);
    // } else if (node->type == Num) {
    //     returh this->visit_Num(node);
    // } else {
    //     return this->visit_default(node);
    // }
    return "";
};

std::string NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return "";
};
