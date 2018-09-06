#include "includes/Interpreter.hpp"


extern std::string T_INTEGER;
extern std::string T_PLUS;
extern std::string T_MINUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_LPAREN;
extern std::string T_RPAREN;

Interpreter::Interpreter(Parser* parser) {
    this->parser = parser;
};

int Interpreter::visit_BinOp(BinOp* node) {
    if (node->op->type == T_PLUS)
        return this->visit(node->left) + this->visit(node->right);
    else if (node->op->type == T_MINUS)
        return this->visit(node->left) - this->visit(node->right);
    else if (node->op->type == T_MULTIPLY)
        return this->visit(node->left) * this->visit(node->right);
    else if (node->op->type == T_DIVIDE)
        return this->visit(node->left) / this->visit(node->right);

    return 0;
};

int Interpreter::visit_Num(Num* node) {
    return std::stoi(node->value);
};

std::string Interpreter::interpret() {
    AST* tree = this->parser->parse();
    return std::to_string(this->visit(tree));
};
