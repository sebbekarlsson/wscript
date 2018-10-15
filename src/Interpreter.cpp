#include "includes/Interpreter.hpp"
#include "includes/typedefs.hpp"
#include <iostream>


Interpreter::Interpreter(Parser* parser) {
    this->parser = parser;
};

void Interpreter::error(std::string message) {
    throw std::runtime_error("[error][Interpreter]:(line=" + std::to_string(this->parser->lexer->line) + ",pos=" + std::to_string(this->parser->lexer->pos) + ") " + message);
};

anything Interpreter::operation(int left, TokenType op, std::string right) {
    if (op == TokenType::Plus)
        return std::to_string(left) + right;

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(std::string left, TokenType op, int right) {
    if (op == TokenType::Plus)
        return left + std::to_string(right);

    this->error(op + " is not supported for string and float");

    return "";
};


anything Interpreter::operation(float left, TokenType op, std::string right) {
    if (op == TokenType::Plus)
        return std::to_string(left) + right;

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(std::string left, TokenType op, float right) {
    if (op == TokenType::Plus)
        return left + std::to_string(right);

    this->error(op + " is not supported for string and float");

    return "";
};

anything Interpreter::operation(float left, TokenType op, float right) {
    if (op == TokenType::Plus)
        return left + right;
    else if (op == TokenType::Minus)
        return left - right;
    else if (op == TokenType::Multiply)
        return left * right;
    else if (op == TokenType::Divide)
        return left / right;
    else if (op == TokenType::Noequals)
        return left != right;
    else if (op == TokenType::Less_than)
        return left < right;
    else if (op == TokenType::Larger_than)
        return left > right;
    else if (op == TokenType::Larger_or_equals)
        return left >= right;
    else if (op == TokenType::Less_or_equals)
        return left <= right;
    else if (op == TokenType::Equals)
        return left == right;

    return 0.0f;
};

anything Interpreter::operation(int left, TokenType op, int right) {
    if (op == TokenType::Plus)
        return left + right;
    else if (op == TokenType::Minus)
        return left - right;
    else if (op == TokenType::Multiply)
        return left * right;
    else if (op == TokenType::Divide)
        return left / right;
    else if (op == TokenType::Noequals)
        return left != right;
    else if (op == TokenType::Less_than)
        return left < right;
    else if (op == TokenType::Larger_than)
        return left > right;
    else if (op == TokenType::Larger_or_equals)
        return left >= right;
    else if (op == TokenType::Less_or_equals)
        return left <= right;
    else if (op == TokenType::Equals)
        return left == right;

    return 0;
};

anything Interpreter::operation(AST* left, TokenType op, AST* right) {
    if (op == TokenType::Noequals)
        return left != right;
    else if (op == TokenType::Equals)
        return left == right;
}

anything Interpreter::operation(anything left, TokenType op, anything right) {
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

    if (left.type() == typeid(AST*) && right.type() == typeid(AST*)) {
        AST* ast = boost::get<AST*>(right);
        if (dynamic_cast<AST_Empty*>(ast)) {
            return this->operation(boost::get<AST*>(left), op, (AST_Empty*)ast);
        }
    }

    if (right.type() == typeid(AST*) && left.type() == typeid(AST*)) {
        AST* ast = boost::get<AST*>(right);
        if (dynamic_cast<AST_Empty*>(ast)) {
            return this->operation(boost::get<AST*>(left), op, (AST_Empty*)ast);
        }
    }

    return 0;
};

anything Interpreter::operation(std::string left, TokenType op, std::string right) {
     if (op == TokenType::Plus)
        return left + right;
     if (op == TokenType::Equals)
         return left == right;
     if (op == TokenType::Noequals)
         return left != right;

     this->error(op + " is not supported for string");
};

anything Interpreter::unary_operation(TokenType op, anything right) {
    if (right.type() == typeid(int))
        return this->unary_operation(op, boost::get<int>(right));

    if (right.type() == typeid(float))
        return this->unary_operation(op, boost::get<float>(right));

    if (right.type() == typeid(std::string))
        return this->unary_operation(op, boost::get<std::string>(right));

    return 0;
};

anything Interpreter::unary_operation(TokenType op, float right) {
    if (op == TokenType::Plus)
        return +right;
    if (op == TokenType::Minus)
        return -right;
    if (op == TokenType::Noequals)
        return !right;

    return 0;
};

anything Interpreter::unary_operation(TokenType op, int right) {
    if (op == TokenType::Plus)
        return +right;
    if (op == TokenType::Minus)
        return -right;
    if (op == TokenType::Noequals)
        return !right;

    return 0;
};

anything Interpreter::unary_operation(TokenType op, std::string right) {
    if (op == TokenType::Noequals)
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
    for (std::vector<AST*>::iterator it = node->children.begin(); it != node->children.end(); ++it)
        this->visit((*it));

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

    if (value.type() == typeid(AST*))
        value = this->visit(boost::get<AST*>(value));

    return value;
};

int Interpreter::visit_AST_VarDecl(AST_VarDecl* node) {
    for (std::vector<Token*>::iterator it = node->tokens.begin(); it != node->tokens.end(); ++it)
        node->get_scope()->set_variable((*it)->value, new AST_Empty(nullptr));

    return 0;
};

int Interpreter::visit_AST_Abstract_Condition(AST_Abstract_Condition* node) {
    std::vector<AST_Abstract_Condition*> conditions;
    conditions.push_back(node);
    for (std::vector<AST_Else*>::iterator it = node->ast_elses.begin(); it != node->ast_elses.end(); ++it)
        conditions.push_back((AST_Abstract_Condition*)(*it));

    for (std::vector<AST_Abstract_Condition*>::iterator it = conditions.begin(); it != conditions.end(); ++it) {
        anything expr = this->visit((*it)->expr);

        if (expr.type() == typeid(int)) {
            int x = boost::get<int>(expr);

            if (x) {
                this->visit((*it)->body);
                return 1;
            }
        }

        if (expr.type() == typeid(bool)) {
            int x = (int)boost::get<bool>(expr);

            if (x) {
                this->visit((*it)->body);
                return 1;
            }
        }

        if (expr.type() == typeid(float)) {
            float x = boost::get<float>(expr);

            if (x) {
                this->visit((*it)->body);
                return 1;
            }
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

anything Interpreter::visit_AST_ArrayAccess(AST_ArrayAccess* node) {
    if (node->args.size() == 0)
        this->error("Accessing array elements requires an argument for index");

    anything index_node = this->visit(node->args[0]);

    if (index_node.type() != typeid(int))
        this->error("Accessing array elements requires an integer index");

    int index = boost::get<int>(index_node);

    if (index > (int)node->array_node->items.size() - 1)
        this->error("Array index out of bounds");

    return node->array_node->items[index];
};

char Interpreter::visit_AST_StringAccess(AST_StringAccess* node) {
    if (node->args.size() == 0)
        this->error("Accessing array elements requires an argument for index");

    anything index_node = this->visit(node->args[0]);

    if (index_node.type() != typeid(int))
        this->error("Accessing array elements requires an integer index");

    int index = boost::get<int>(index_node);

    if (index > (int)node->value.size() - 1)
        this->error("Array index out of bounds");

    return node->value[index];
};

anything Interpreter::visit_AST_functionCall(AST_FunctionCall* node) {
    int missing_arguments = 0;

    if (dynamic_cast<AST_UserDefinedFunctionCall*>( node )) {
        anything ret = (anything)0;

        AST_UserDefinedFunctionCall* udfc = (AST_UserDefinedFunctionCall*) node;
        
        AST_BuiltinFunctionDefinition* bfd = node->get_scope()->get_builtin_function(udfc->name);

        if (bfd != nullptr) {
            if (!bfd->unlimited_args) {
                missing_arguments = bfd->expected_args.size() - node->args.size();
                if (missing_arguments > 0)
                    this->error("Missing " + std::to_string(missing_arguments) + " arguments when calling: " + bfd->name);
            }

            return this->visit(bfd->call(node->args, this));
        }

        // be ble to access array and string elements using `(` and `)`
        if (udfc->get_scope()->has_variable(udfc->name)) {
            anything var = udfc->get_scope()->get_variable(udfc->name);

            if (var.type() == typeid(AST*)) {
                AST* ast = boost::get<AST*>(var);

                if (dynamic_cast<AST_Array*>(ast)) {
                    AST_Array* arr = (AST_Array*)ast;
                    AST_ArrayAccess* array_access = new AST_ArrayAccess(arr, node->args);

                    return this->visit(array_access);
                } 
            } else if (var.type() == typeid(std::string)) {
                std::string value = boost::get<std::string>(var);
                AST_StringAccess* string_access = new AST_StringAccess(value, node->args);

                return this->visit(string_access);
            }
        }
        
        udfc->definition = node->get_scope()->get_function_definition(udfc->name);

        if (udfc->definition == nullptr)
            this->error("Could not find definition for: " + udfc->name);

        missing_arguments = udfc->definition->args.size() - node->args.size();

        if (missing_arguments > 0)
            this->error("Missing " + std::to_string(missing_arguments) + " arguments when calling: " + udfc->name);


        int i = 0;
        for (std::vector<Token*>::iterator it = udfc->definition->args.begin(); it != udfc->definition->args.end(); ++it) {
            udfc->definition->get_scope()->set_variable((*it)->value, this->visit(node->args[i]));
            i++;
        }
        
        ret = this->visit(udfc->call(this));
        ret = udfc->definition->scope->value;

        return ret;
    }

    return this->visit(node->call(this));
};

anything Interpreter::visit_AST_functionDefinition(AST_FunctionDefinition* node) {
    node->get_parent_scope()->define_function(node);
    node->get_scope()->define_function(node);
    return new AST_NoOp();
}

anything Interpreter::visit_AST_Return(AST_Return* node) {
    node->scope->value = this->visit(node->value);
    return node->scope->value;
};

anything Interpreter::visit_AST_AttributeAccess(AST_AttributeAccess* node) {
    // TODO: visit the left node, fetch that scope and invite the right
    // node to that scope.
    //
    // .. we might have to add `Scope` to all AST:s,
    // this would mean that all AST:s could have a functions and variables...
    // (which does make sense)
    anything left = this->visit(node->left);

    if (left.type() != typeid(AST*))
        this->error("Cannot access attributes from this data type");

    AST* element = (AST*) boost::get<AST*>( left );
    node->right->scope = element->private_scope;
    node->scope = element->private_scope;

    return this->visit(node->right);
}

AST_Object* Interpreter::visit_AST_Object(AST_Object* node) {
    return node;
};

anything Interpreter::visit_AST_Array(AST_Array* node) {
    return node;
}

AST_Empty* Interpreter::visit_AST_Empty(AST_Empty* node) {
    return node;
};

int Interpreter::visit_AST_NoOp(AST_NoOp* node) { return 0; };

anything Interpreter::interpret() {
    AST* tree = this->parser->parse();
    anything x = this->visit(tree);
    
    return x;
};
