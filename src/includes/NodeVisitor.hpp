#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST.hpp"
#include "BinOp.hpp"
#include "Num.hpp"
#include <string>


class NodeVisitor {
    public:
        std::string visit(AST* node);
        std::string visit_default(AST* node);

        virtual std::string visit_BinOp(BinOp* node) = 0;
        virtual std::string visit_Num(Num* node) = 0;
};
#endif
