#include "includes/NodeVisitor.hpp"
#include <iostream>


// there are problems with (anything)this method and the problem is
// that it always returns an integer. This makes it difficult
// to work with other types such as floats, doubles, strings, objects etc..
anything NodeVisitor::visit(AST* node) {
    if (dynamic_cast<AST_BinOp*>( node ))
        return (anything)this->visit_AST_BinOp((AST_BinOp*) node);
    else if (dynamic_cast<AST_UnaryOp*>( node ))
        return (anything)this->visit_AST_UnaryOp((AST_UnaryOp*) node);
    else if (dynamic_cast<AST_Integer*>( node ))
        return (anything)this->visit_AST_Integer((AST_Integer*) node);
    else if (dynamic_cast<AST_Float*>( node ))
        return (anything)this->visit_AST_Float((AST_Float*) node);
    else if (dynamic_cast<AST_Str*>( node ))
        return (anything)this->visit_AST_Str((AST_Str*) node); // TODO: fix
    else if (dynamic_cast<AST_Var*>( node ))
        return (anything)this->visit_AST_Var((AST_Var*) node);
    else if (dynamic_cast<AST_VarDecl*>( node ))
        return (anything)this->visit_AST_VarDecl((AST_VarDecl*) node);
    else if (dynamic_cast<AST_Compound*>( node ))
        return (anything)this->visit_AST_Compound((AST_Compound*) node);
    else if (dynamic_cast<AST_Assign*>( node ))
        return (anything)this->visit_AST_Assign((AST_Assign*) node);
    else if (dynamic_cast<AST_Abstract_Condition*>( node ))
        return (anything)this->visit_AST_Abstract_Condition((AST_Abstract_Condition*) node);
    else if (dynamic_cast<AST_DoWhile*>( node ))
        return (anything)this->visit_AST_DoWhile((AST_DoWhile*) node);
    else if (dynamic_cast<AST_FunctionCall*>( node ))
        return (anything)this->visit_AST_functionCall((AST_FunctionCall*) node);
    else if (dynamic_cast<AST_FunctionDefinition*>( node ))
        return (anything)this->visit_AST_functionDefinition((AST_FunctionDefinition*) node);
    else if (dynamic_cast<AST_Return*>( node ))
        return (anything)this->visit_AST_Return((AST_Return*) node);
    else if (dynamic_cast<AST_AttributeAccess*>( node ))
        return (anything)this->visit_AST_AttributeAccess((AST_AttributeAccess*) node);
    else if (dynamic_cast<AST_NoOp*>( node ))
        return (anything)this->visit_AST_NoOp((AST_NoOp*) node);
    else if (dynamic_cast<AST_Object*>( node ))
        return (anything)this->visit_AST_Object((AST_Object*) node);
    else if (dynamic_cast<AST_Array*>( node ))
        return (anything)this->visit_AST_Array((AST_Array*) node);
    else if (dynamic_cast<AST_ArrayAccess*>( node ))
        return (anything)this->visit_AST_ArrayAccess((AST_ArrayAccess*) node);
    else if (dynamic_cast<AST_StringAccess*>( node ))
        return (anything)this->visit_AST_StringAccess((AST_StringAccess*) node);

    return (anything)this->visit_default(node);
};

anything NodeVisitor::visit_default(AST* node) {
    // TODO: Throw error here
    return (anything)0;
};
