#include "includes/Interpreter.hpp"
#include <iostream>


extern std::string T_INTEGER;
extern std::string T_PLUS;
extern std::string T_MINUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_LPAREN;
extern std::string T_RPAREN;
extern std::string T_LESS_THAN;
extern std::string T_LARGER_THAN;
extern std::string T_LARGER_OR_EQUALS;
extern std::string T_LESS_OR_EQUALS;
extern std::string T_NOT_EQUALS;
extern std::string T_EQUALS;

Interpreter::Interpreter(Parser* parser) {
    this->parser = parser;
};

void Interpreter::error(std::string message) {
    throw std::runtime_error("[error][Interpreter]:(line=" + std::to_string(this->parser->lexer->line) + ",pos=" + std::to_string(this->parser->lexer->pos) + ") " + message);
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
    else if (node->op->type == T_NOT_EQUALS)
        return this->visit(node->left) != this->visit(node->right);
    else if (node->op->type == T_LESS_THAN)
        return this->visit(node->left) < this->visit(node->right);
    else if (node->op->type == T_LARGER_THAN)
        return this->visit(node->left) > this->visit(node->right);
    else if (node->op->type == T_LARGER_OR_EQUALS)
        return this->visit(node->left) >= this->visit(node->right);
    else if (node->op->type == T_LESS_OR_EQUALS)
        return this->visit(node->left) <= this->visit(node->right);
    else if (node->op->type == T_EQUALS)
        return this->visit(node->left) == this->visit(node->right);

    return 0;
};

int Interpreter::visit_UnaryOp(UnaryOp * node) {
    if (node->op->type == T_PLUS)
        return +this->visit(node->expr);
    else if (node->op->type == T_MINUS)
        return -this->visit(node->expr);
    else if (node->op->type == T_NOT_EQUALS) {
        return !this->visit(node->expr);
    }

    return this->visit(node->expr);
}

int Interpreter::visit_Num(Num* node) {
    return node->value;
};

int Interpreter::visit_Compound(Compound* node) {
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
        this->visit((*it));
    }

    return 0;
};

int Interpreter::visit_Assign(Assign* node) {
    std::string varname = node->left->value;
    
    if (!RAM::has_variable(varname))
        this->error("Trying to assign to undeclared variable: `" + varname + "`");

    int value = this->visit(node->right);

    RAM::set_variable(varname, std::to_string(value));

    return value;
};

int Interpreter::visit_Var(Var* node) {
    std::string varname = node->value;
    std::string value = RAM::get_variable(varname);

    return std::stoi(value);
};

int Interpreter::visit_VarDecl(VarDecl* node) {
    RAM::set_variable(node->key, "");

    return 0;
};


int Interpreter::visit_If(If* node) {
    bool comp = this->visit(node->comp);

    if (comp)
        return this->visit(node->root);

    return 0;
};

int Interpreter::visit_functionCall(FunctionCall* node) {
    std::vector<int> _args;

    for (std::vector<AST*>::iterator it = node->args.begin(); it != node->args.end(); ++it)
        _args.push_back(this->visit((*it)));

    return this->visit(node->call(_args));
};

int Interpreter::visit_NoOp(NoOp* node) { return 0; };

int Interpreter::interpret() {
    AST* tree = this->parser->parse();
    return this->visit(tree);
};
