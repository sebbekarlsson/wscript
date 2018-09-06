#include "includes/Interpreter.hpp"


Interpreter::Interpreter(Parser* parser) {
    this->parser = parser;
};

std::string Interpreter::visit_BinOp(BinOp* node) {
    return "";
};

std::string Interpreter::visit_Num(Num* num) {
    return "";
};

std::string Interpreter::interpret() {
    AST* tree = this->parser->parse();
    return this->visit(tree);
};
