#include "includes/NodeVisitor.hpp"


std::string NodeVisitor::visit(AST* node) {
    return "";
};

std::string NodeVisitor::visit_default(AST* node) {
    return "";
};
