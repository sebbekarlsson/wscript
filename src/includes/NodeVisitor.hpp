#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST.hpp"
#include "BinOp.hpp"
#include "UnaryOp.hpp"
#include "Num.hpp"
#include <string>


class NodeVisitor {
    public:
        int visit(AST* node);
        int visit_default(AST* node);

        virtual int visit_BinOp(BinOp* node) = 0;
        virtual int visit_UnaryOp(UnaryOp* node) = 0;
        virtual int visit_Num(Num* node) = 0;
};
#endif
