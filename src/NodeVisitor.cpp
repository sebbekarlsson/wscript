#include "includes/NodeVisitor.hpp"


int NodeVisitor::visit(AST* node) {
    if (node->name == "BinOp")
        return this->visit_BinOp((BinOp*) node);
    else if (node->name == "Num")
        return this->visit_Num((Num*) node);
    else
        return this->visit_default(node);
};

int NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return 0;
};
