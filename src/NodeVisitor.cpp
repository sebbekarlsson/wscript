#include "includes/NodeVisitor.hpp"
#include <iostream>


int NodeVisitor::visit(AST* node) {
    if (node->name == "BinOp")
        return this->visit_BinOp((BinOp*) node);
    else if (node->name == "UnaryOp")
        return this->visit_UnaryOp((UnaryOp*) node);
    else if (node->name == "Num")
        return this->visit_Num((Num*) node);
    else if (node->name == "Var")
        return this->visit_Var((Var*) node);
    else if (node->name == "VarDecl")
        return this->visit_VarDecl((VarDecl*) node);
    else if (node->name == "Compound")
        return this->visit_Compound((Compound*) node);
    else if (node->name == "Assign")
        return this->visit_Assign((Assign*) node);
    else if (node->name == "If")
        return this->visit_If((If*) node);
    else if (node->name == "NoOp")
        return this->visit_NoOp((NoOp*) node);
    
    return this->visit_default(node);
};

int NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return 0;
};
