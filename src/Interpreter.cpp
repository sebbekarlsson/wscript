#include "includes/Interpreter.hpp"
#include "includes/typedefs.hpp"
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

anything Interpreter::operation(int left, std::string op, std::string right) {
    if (op == T_PLUS)
        return std::to_string(left) + right;

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(std::string left, std::string op, int right) {
    if (op == T_PLUS)
        return left + std::to_string(right);

    this->error(op + " is not supported for string and float");

    return "";
};


anything Interpreter::operation(float left, std::string op, std::string right) {
    if (op == T_PLUS)
        return std::to_string(left) + right;

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(std::string left, std::string op, float right) {
    if (op == T_PLUS)
        return left + std::to_string(right);

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(float left, std::string op, float right) {
    if (op == T_PLUS)
        return left + right;
    else if (op == T_MINUS)
        return left - right;
    else if (op == T_MULTIPLY)
        return left * right;
    else if (op == T_DIVIDE)
        return left / right;
    else if (op == T_NOT_EQUALS)
        return left != right;
    else if (op == T_LESS_THAN)
        return left < right;
    else if (op == T_LARGER_THAN)
        return left > right;
    else if (op == T_LARGER_OR_EQUALS)
        return left >= right;
    else if (op == T_LESS_OR_EQUALS)
        return left <= right;
    else if (op == T_EQUALS)
        return left == right;

    return 0.0f;
};

anything Interpreter::operation(int left, std::string op, int right) {
    if (op == T_PLUS)
        return left + right;
    else if (op == T_MINUS)
        return left - right;
    else if (op == T_MULTIPLY)
        return left * right;
    else if (op == T_DIVIDE)
        return left / right;
    else if (op == T_NOT_EQUALS)
        return left != right;
    else if (op == T_LESS_THAN)
        return left < right;
    else if (op == T_LARGER_THAN)
        return left > right;
    else if (op == T_LARGER_OR_EQUALS)
        return left >= right;
    else if (op == T_LESS_OR_EQUALS)
        return left <= right;
    else if (op == T_EQUALS)
        return left == right;

    return 0;
};

anything Interpreter::operation(anything left, std::string op, anything right) {
    if (left.type() == typeid(int) && right.type() == typeid(int))
        return this->operation(boost::get<int>(left), op, boost::get<int>(right));

    if (left.type() == typeid(float) && right.type() == typeid(float))
        return this->operation(boost::get<float>(left), op, boost::get<float>(right));

    if (left.type() == typeid(bool) && right.type() == typeid(bool))
        return this->operation((int)boost::get<bool>(left), op, (int)boost::get<bool>(right));

    if (left.type() == typeid(std::string) && right.type() == typeid(std::string))
        return this->operation(boost::get<std::string>(left), op, boost::get<std::string>(right));

    if (left.type() == typeid(std::string) && right.type() == typeid(int))
        return this->operation(boost::get<std::string>(left), op, boost::get<int>(right));

    if (left.type() == typeid(int) && right.type() == typeid(std::string))
        return this->operation(boost::get<int>(left), op, boost::get<std::string>(right));

    if (left.type() == typeid(std::string) && right.type() == typeid(float))
        return this->operation(boost::get<std::string>(left), op, boost::get<float>(right));

    if (left.type() == typeid(float) && right.type() == typeid(std::string))
        return this->operation(boost::get<float>(left), op, boost::get<std::string>(right));

    return 0;
};

anything Interpreter::operation(std::string left, std::string op, std::string right) {
     if (op == T_PLUS)
        return left + right;
     if (op == T_EQUALS)
         return left == right;
     if (op == T_NOT_EQUALS)
         return left != right;

     this->error(op + " is not supported for string");
};

anything Interpreter::unary_operation(std::string op, anything right) {
    if (right.type() == typeid(int))
        return this->unary_operation(op, boost::get<int>(right));

    if (right.type() == typeid(float))
        return this->unary_operation(op, boost::get<float>(right));

    if (right.type() == typeid(std::string))
        return this->unary_operation(op, boost::get<std::string>(right));

    return 0;
};

anything Interpreter::unary_operation(std::string op, float right) {
    if (op == T_PLUS)
        return +right;
    if (op == T_MINUS)
        return -right;
    if (op == T_NOT_EQUALS)
        return !right;

    return 0;
};

anything Interpreter::unary_operation(std::string op, int right) {
    if (op == T_PLUS)
        return +right;
    if (op == T_MINUS)
        return -right;
    if (op == T_NOT_EQUALS)
        return !right;

    return 0;
};

anything Interpreter::unary_operation(std::string op, std::string right) {
    if (op == T_NOT_EQUALS)
        return right.empty();

    this->error(op + " is not supported for string");

    return 0;
};

anything Interpreter::visit_AST_BinOp(AST_BinOp* node) {
    return this->operation(this->visit(node->left), node->token->type, this->visit(node->right));
};

anything Interpreter::visit_AST_UnaryOp(AST_UnaryOp * node) {
    return this->unary_operation(node->op->type, this->visit(node->expr));
}

int Interpreter::visit_AST_Integer(AST_Integer* node) {
    return node->token->get_integer();
};

float Interpreter::visit_AST_Float(AST_Float* node) {
    return node->token->get_float();
};

std::string Interpreter::visit_AST_Str(AST_Str* node) {
    return node->token->get_string(); // TODO: return string
};

int Interpreter::visit_AST_Compound(AST_Compound* node) {
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it) {
        this->visit((*it));
    }

    return 0;
};

anything Interpreter::visit_AST_Assign(AST_Assign* node) {
    std::string varname = node->left->value;
    
    if (!node->get_scope()->has_variable(varname))
        this->error("Trying to assign to undeclared variable: `" + varname + "`");

    anything value = this->visit(node->right);

    node->get_scope()->set_variable(varname, value);

    return value;
};

anything Interpreter::visit_AST_Var(AST_Var* node) {
    std::string varname = node->value;
    anything value = node->get_scope()->get_variable(varname);

    return value;
};

int Interpreter::visit_AST_VarDecl(AST_VarDecl* node) {
    for (std::vector<Token*>::iterator it = node->tokens.begin(); it != node->tokens.end(); ++it)
        node->get_scope()->set_variable((*it)->value, "");

    return 0;
};

int Interpreter::visit_AST_If(AST_If* node) {
    anything comp = this->visit(node->comp);

    if (comp.type() == typeid(int)) {
        int x = boost::get<int>(comp);

        if (x) {
            this->visit(node->root);
            return 1;
        }
    }

    if (comp.type() == typeid(bool)) {
        int x = (int)boost::get<bool>(comp);

        if (x) {
            this->visit(node->root);
            return 1;
        }
    }

    if (comp.type() == typeid(float)) {
        float x = boost::get<float>(comp);

        if (x) {
            this->visit(node->root);
            return 1;
        }
    }

    return 0;
};

int Interpreter::visit_AST_DoWhile(AST_DoWhile* node) {
    int loop = false;
    anything expr = this->visit(node->expr);

    if (expr.type() == typeid(int))
        loop = boost::get<int>(expr);
    else if (expr.type() == typeid(float))
        loop = (int)boost::get<float>(expr);
    else if (expr.type() == typeid(bool))
        loop = (int)boost::get<bool>(expr);

    while (loop) {
        this->visit(node->body);
        expr = this->visit(node->expr);

        if (expr.type() == typeid(int))
            loop = boost::get<int>(expr);
        else if (expr.type() == typeid(float))
            loop = (int)boost::get<float>(expr);
        else if (expr.type() == typeid(bool))
            loop = (int)boost::get<bool>(expr);
    }

    return 1;
};

anything Interpreter::visit_AST_functionCall(AST_FunctionCall* node) {
    if (dynamic_cast<AST_UserDefinedFunctionCall*>( node )) {
        AST_UserDefinedFunctionCall* udfc = (AST_UserDefinedFunctionCall*) node;
        udfc->definition = node->get_scope()->get_function_definition(udfc->name);
        if (udfc->definition == nullptr)
            this->error("Could not find definition for: " + udfc->name);

        int missing_arguments = udfc->definition->args.size() - node->args.size();

        if (missing_arguments > 0)
            this->error("Missing " + std::to_string(missing_arguments) + " arguments when calling: " + udfc->name);

        int i = 0;
        for (std::vector<Token*>::iterator it = udfc->definition->args.begin(); it != udfc->definition->args.end(); ++it) {
            udfc->definition->get_scope()->set_variable((*it)->value, this->visit(node->args[i]));
            i++;
        }

        return this->visit(udfc->call(this));
    }

    return this->visit(node->call(this));
};

anything Interpreter::visit_AST_functionDefinition(AST_FunctionDefinition* node) {
    node->get_scope()->define_function(node);
    return new AST_NoOp();
}

int Interpreter::visit_AST_NoOp(AST_NoOp* node) { return 0; };

anything Interpreter::interpret() {
    AST* tree = this->parser->parse();
    anything x = this->visit(tree);
    
    return x;
};
