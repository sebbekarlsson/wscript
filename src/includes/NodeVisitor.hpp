#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST/AST.hpp"
#include "AST/AST_BinOp.hpp"
#include "AST/AST_UnaryOp.hpp"
#include "AST/AST_Num.hpp"
#include "AST/AST_Compound.hpp"
#include "AST/AST_NoOp.hpp"
#include "AST/AST_Assign.hpp"
#include "AST/AST_Var.hpp"
#include "AST/AST_VarDecl.hpp"
#include "AST/AST_If.hpp"
#include "AST/AST_FunctionCall.hpp"
#include <string>


class NodeVisitor {
    public:
        int visit(AST* node);
        int visit_default(AST* node);

        virtual int visit_AST_BinOp(AST_BinOp* node) = 0;
        virtual int visit_AST_UnaryOp(AST_UnaryOp* node) = 0;
        virtual int visit_AST_Num(AST_Num* node) = 0;
        virtual int visit_AST_Assign(AST_Assign* node) = 0;
        virtual int visit_AST_Var(AST_Var* node) = 0;
        
        virtual int visit_AST_Compound(AST_Compound* node) = 0;
        virtual int visit_AST_NoOp(AST_NoOp* node) = 0;
        virtual int visit_AST_VarDecl(AST_VarDecl* node) = 0;
        virtual int visit_AST_If(AST_If* node) = 0;
        virtual int visit_AST_functionCall(AST_FunctionCall* node) = 0;
};
#endif
