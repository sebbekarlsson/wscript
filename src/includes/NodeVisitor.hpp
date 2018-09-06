#ifndef NODEVISITOR_H
#define NODEVISITOR_H
#include "AST.hpp"
#include <string>


class NodeVisitor {
    public:
        std::string visit(AST* node);
        std::string visit_default(AST* node);
};
#endif
