#include "includes/NodeVisitor.hpp"
#include <iostream>


int NodeVisitor::visit(AST* node) {
    if (dynamic_cast<AST_BinOp*>( node ))
        return this->visit_AST_BinOp((AST_BinOp*) node);
    else if (dynamic_cast<AST_UnaryOp*>( node ))
        return this->visit_AST_UnaryOp((AST_UnaryOp*) node);
    else if (dynamic_cast<AST_Num*>( node ))
        return this->visit_AST_Num((AST_Num*) node);
    else if (dynamic_cast<AST_Var*>( node ))
        return this->visit_AST_Var((AST_Var*) node);
    else if (dynamic_cast<AST_VarDecl*>( node ))
        return this->visit_AST_VarDecl((AST_VarDecl*) node);
    else if (dynamic_cast<AST_Compound*>( node ))
        return this->visit_AST_Compound((AST_Compound*) node);
    else if (dynamic_cast<AST_Assign*>( node ))
        return this->visit_AST_Assign((AST_Assign*) node);
    else if (dynamic_cast<AST_If*>( node ))
        return this->visit_AST_If((AST_If*) node);
    else if (dynamic_cast<AST_FunctionCall*>( node ))
        return this->visit_AST_functionCall((AST_FunctionCall*) node);
    else if (dynamic_cast<AST_NoOp*>( node ))
        return this->visit_AST_NoOp((AST_NoOp*) node);
    
    return this->visit_default(node);
};

int NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return 0;
};
