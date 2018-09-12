#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST.hpp"
#include "BinOp.hpp"
#include "UnaryOp.hpp"
#include "Num.hpp"
#include "Compound.hpp"
#include "NoOp.hpp"
#include "Assign.hpp"
#include "Var.hpp"
#include "VarDecl.hpp"
#include "If.hpp"
#include "FunctionCall.hpp"
#include <string>


class NodeVisitor {
    public:
        int visit(AST* node);
        int visit_default(AST* node);

        virtual int visit_BinOp(BinOp* node) = 0;
        virtual int visit_UnaryOp(UnaryOp* node) = 0;
        virtual int visit_Num(Num* node) = 0;
        virtual int visit_Assign(Assign* node) = 0;
        virtual int visit_Var(Var* node) = 0;
        
        virtual int visit_Compound(Compound* node) = 0;
        virtual int visit_NoOp(NoOp* node) = 0;
        virtual int visit_VarDecl(VarDecl* node) = 0;
        virtual int visit_If(If* node) = 0;
        virtual int visit_functionCall(FunctionCall* node) = 0;
};
#endif
