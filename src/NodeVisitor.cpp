#include "includes/NodeVisitor.hpp"
#include <iostream>


int NodeVisitor::visit(AST* node) {
    if (node->name == "AST_BinOp")
        return this->visit_AST_BinOp((AST_BinOp*) node);
    else if (node->name == "AST_UnaryOp")
        return this->visit_AST_UnaryOp((AST_UnaryOp*) node);
    else if (node->name == "AST_Num")
        return this->visit_AST_Num((AST_Num*) node);
    else if (node->name == "AST_Var")
        return this->visit_AST_Var((AST_Var*) node);
    else if (node->name == "AST_VarDecl")
        return this->visit_AST_VarDecl((AST_VarDecl*) node);
    else if (node->name == "AST_Compound")
        return this->visit_AST_Compound((AST_Compound*) node);
    else if (node->name == "AST_Assign")
        return this->visit_AST_Assign((AST_Assign*) node);
    else if (node->name == "AST_If")
        return this->visit_AST_If((AST_If*) node);
    else if (node->name == "AST_FunctionCall")
        return this->visit_AST_functionCall((AST_FunctionCall*) node);
    else if (node->name == "AST_NoOp")
        return this->visit_AST_NoOp((AST_NoOp*) node);
    
    return this->visit_default(node);
};

int NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return 0;
};
