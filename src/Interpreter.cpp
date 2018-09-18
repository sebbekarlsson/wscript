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

int Interpreter::visit_AST_BinOp(AST_BinOp* node) {
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

int Interpreter::visit_AST_UnaryOp(AST_UnaryOp * node) {
    if (node->op->type == T_PLUS)
        return +this->visit(node->expr);
    else if (node->op->type == T_MINUS)
        return -this->visit(node->expr);
    else if (node->op->type == T_NOT_EQUALS) {
        return !this->visit(node->expr);
    }

    return this->visit(node->expr);
}

int Interpreter::visit_AST_Num(AST_Num* node) {
    return node->value;
};

std::string Interpreter::visit_AST_Str(AST_Str* node) {
    return node->value;
};

int Interpreter::visit_AST_Compound(AST_Compound* node) {
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
        this->visit((*it));
    }

    return 0;
};

int Interpreter::visit_AST_Assign(AST_Assign* node) {
    std::string varname = node->left->value;
    
    if (!RAM::has_variable(varname))
        this->error("Trying to assign to undeclared variable: `" + varname + "`");

    int value = this->visit(node->right);

    RAM::set_variable(varname, std::to_string(value));

    return value;
};

int Interpreter::visit_AST_Var(AST_Var* node) {
    std::string varname = node->value;
    std::string value = RAM::get_variable(varname);

    return std::stoi(value);
};

int Interpreter::visit_AST_VarDecl(AST_VarDecl* node) {
    for (std::vector<Token*>::iterator it = node->tokens.begin(); it != node->tokens.end(); ++it)
        RAM::set_variable((*it)->value, "");

    return 0;
};

int Interpreter::visit_AST_If(AST_If* node) {
    bool comp = this->visit(node->comp);

    return this->visit(node->root) ? comp : 0;
};

int Interpreter::visit_AST_functionCall(AST_FunctionCall* node) {
    std::vector<int> _args;

    for (std::vector<AST*>::iterator it = node->args.begin(); it != node->args.end(); ++it)
        _args.push_back(this->visit((*it)));

    return this->visit(node->call(_args));
};

int Interpreter::visit_AST_NoOp(AST_NoOp* node) { return 0; };

int Interpreter::interpret() {
    AST* tree = this->parser->parse();
    return this->visit(tree);
};
