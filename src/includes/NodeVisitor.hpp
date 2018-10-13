#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST/AST.hpp"
#include "AST/AST_BinOp.hpp"
#include "AST/AST_UnaryOp.hpp"
#include "AST/AST_Integer.hpp"
#include "AST/AST_Float.hpp"
#include "AST/AST_Str.hpp"
#include "AST/AST_Compound.hpp"
#include "AST/AST_NoOp.hpp"
#include "AST/AST_Assign.hpp"
#include "AST/AST_Var.hpp"
#include "AST/AST_VarDecl.hpp"
#include "AST/AST_Abstract_Condition.hpp"
#include "AST/AST_FunctionCall.hpp"
#include "AST/AST_UserDefinedFunctionCall.hpp"
#include "AST/AST_FunctionDefinition.hpp"
#include "AST/AST_DoWhile.hpp"
#include "AST/AST_Return.hpp"
#include "AST/AST_AttributeAccess.hpp"
#include "AST/AST_Object.hpp"
#include "AST/AST_Array.hpp"
#include <string>
#include "typedefs.hpp"



class NodeVisitor {
    public:
        anything visit(AST* node);
        anything visit_default(AST* node);

        virtual anything visit_AST_BinOp(AST_BinOp* node) = 0;
        virtual anything visit_AST_UnaryOp(AST_UnaryOp* node) = 0;
        virtual int visit_AST_Integer(AST_Integer* node) = 0;
        virtual float visit_AST_Float(AST_Float* node) = 0;
        virtual anything visit_AST_Assign(AST_Assign* node) = 0;
        virtual anything visit_AST_Var(AST_Var* node) = 0;
        virtual int visit_AST_Compound(AST_Compound* node) = 0;
        virtual int visit_AST_NoOp(AST_NoOp* node) = 0;
        virtual int visit_AST_VarDecl(AST_VarDecl* node) = 0;
        virtual int visit_AST_Abstract_Condition(AST_Abstract_Condition* node) = 0;
        virtual int visit_AST_DoWhile(AST_DoWhile* node) = 0;
        virtual anything visit_AST_functionCall(AST_FunctionCall* node) = 0;
        virtual anything visit_AST_functionDefinition(AST_FunctionDefinition* node) = 0;
        virtual anything visit_AST_Return(AST_Return* node) = 0;
        virtual anything visit_AST_AttributeAccess(AST_AttributeAccess* node) = 0;
        virtual std::string visit_AST_Str(AST_Str* node) = 0;

        virtual AST_Object* visit_AST_Object(AST_Object* node) = 0;
        virtual anything visit_AST_Array(AST_Array* node) = 0;
};
#endif
