#include "includes/Parser.hpp"
#include "includes/AST/AST_Integer.hpp"
#include "includes/AST/AST_Float.hpp"
#include "includes/AST/AST_Str.hpp"
#include "includes/AST/AST_BinOp.hpp"
#include "includes/AST/AST_UnaryOp.hpp"
#include "includes/AST/AST_NoOp.hpp"
#include "includes/AST/AST_Compound.hpp"
#include "includes/AST/AST_Var.hpp"
#include "includes/AST/AST_Assign.hpp"
#include "includes/AST/AST_VarDecl.hpp"
#include "includes/AST/AST_If.hpp"
#include "includes/AST/AST_Else.hpp"
#include "includes/AST/AST_PrintCall.hpp"
#include "includes/AST/AST_UserDefinedFunctionCall.hpp"
#include "includes/AST/AST_DoWhile.hpp"
#include <ctype.h>
#include <iostream>
#include <sstream>


extern std::string T_INTEGER;
extern std::string T_STRING;
extern std::string T_FLOAT;
extern std::string T_PLUS;
extern std::string T_MINUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_LPAREN;
extern std::string T_RPAREN;
extern std::string T_DOT;
extern std::string T_BEGIN;
extern std::string T_END;
extern std::string T_ID;
extern std::string T_SEMI;
extern std::string T_ASSIGN;
extern std::string T_DECLARE;
extern std::string T_NEWLINE;
extern std::string T_LARGER_THAN;
extern std::string T_LESS_THAN;
extern std::string T_LARGER_OR_EQUALS;
extern std::string T_LESS_OR_EQUALS;
extern std::string T_NOT_EQUALS;
extern std::string T_EQUALS;
extern std::string T_IF;
extern std::string T_ELSE;
extern std::string T_ELSE_IF;
extern std::string T_THEN;
extern std::string T_EOF;
extern std::string T_FUNCTION_CALL;
extern std::string T_FUNCTION_DEFINITION;
extern std::string T_COMMA;
extern std::string T_COLON;
extern std::string T_DO;
extern std::string T_LOOP;
extern std::string T_WHILE;

Parser::Parser(Lexer* lexer) {
    this->lexer = lexer;
    this->current_token = this->lexer->get_next_token();
};

/**
 * Takes an expected token_type as argument,
 * if the current_token->type is equal to that, it will
 * fetch the next token and assign it to this->current_token.
 *
 * If the token_type passed in is not equal to the current one, it will
 * throw an error.
 *
 * @param std::string token_type - the expected current token type.
 */
void Parser::eat(std::string token_type) {
    if (this->current_token->type == token_type)
        this->current_token = this->lexer->get_next_token();
    else
        this->error("Expected token type: `" + token_type + "`, but got `" + this->current_token->type + "`");
};

/**
 * Raises an error
 *
 * @param std::string message
 */
void Parser::error(std::string message) {
    throw std::runtime_error("[error][Parser](line=" + std::to_string(this->lexer->line) + ",pos=" + std::to_string(this->lexer->pos) + "): " + message);
};

/**
 * @return AST*
 */
AST* Parser::factor() {
    Token* token = this->current_token;

    if (token->type == T_PLUS) {
        this->eat(T_PLUS);
        AST_UnaryOp* node = new AST_UnaryOp(token, this->factor());
        return node;

    } else if (token->type == T_MINUS) {
        this->eat(T_MINUS);
        AST_UnaryOp* node = new AST_UnaryOp(token, this->factor());
        return node;
    
    } else if (token->type == T_NOT_EQUALS) {
        this->eat(T_NOT_EQUALS);
        AST_UnaryOp* node = new AST_UnaryOp(token, this->factor());
        return node;

    } else if (token->type == T_INTEGER) {
        this->eat(T_INTEGER);
        AST_Integer* num = new AST_Integer(token);
        return num;

    } else if (token->type == T_STRING) {
        this->eat(T_STRING);
        AST_Str* node = new AST_Str(token);
        return node;
    
    } else if (token->type == T_FLOAT) {
        this->eat(T_FLOAT);
        AST_Float* num = new AST_Float(token);
        return num;

    } else if (token->type == T_LPAREN) {
        this->eat(T_LPAREN);
        AST* node = this->expr();
        this->eat(T_RPAREN);
        return node;
    } else if (token->type == T_FUNCTION_CALL) {
        AST* node = this->function_call();
        return node;
    } else {
        AST* node = this->variable();
        return node;
    }

    return nullptr;
};

/**
 * Handles multiplication and division
 * term : factor ((MUL | DIV) factor)*
 *
 * @return AST*
 */
AST* Parser::term() {
    Token* token = nullptr;

    AST* node = this->factor();
    
    while (
        this->current_token->type == T_MULTIPLY ||
        this->current_token->type == T_DIVIDE
    ) {
        token = this->current_token;

        if (token->type == T_MULTIPLY) {
            this->eat(T_MULTIPLY);
        } else if (token->type == T_DIVIDE) {
            this->eat(T_DIVIDE);
        }

        node = new AST_BinOp(node, token, this->factor());
    }

    return node;
};

/**
 * Tells the interpreter to parse a mathematical expression,
 * arithmetic expression parsing.
 *
 * @return std::string
 */
AST* Parser::expr() {
    Token* token = nullptr;

    AST* node = this->term();
    
    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS ||
        this->current_token->type == T_NOT_EQUALS ||
        this->current_token->type == T_LESS_THAN ||
        this->current_token->type == T_LARGER_THAN ||
        this->current_token->type == T_LESS_OR_EQUALS ||
        this->current_token->type == T_LARGER_OR_EQUALS ||
        this->current_token->type == T_EQUALS
    ) {
        token = this->current_token;

        if (token->type == T_PLUS) {
            this->eat(T_PLUS);
        } else if (token->type == T_MINUS) {
            this->eat(T_MINUS);
        } else if (token->type == T_NOT_EQUALS) {
            this->eat(T_NOT_EQUALS);
        } else if (token->type == T_LESS_THAN) {
            this->eat(T_LESS_THAN);
        } else if (token->type == T_LARGER_THAN) {
            this->eat(T_LARGER_THAN);
        } else if (token->type == T_LESS_OR_EQUALS) {
            this->eat(T_LESS_OR_EQUALS);
        } else if (token->type == T_EQUALS) {
            this->eat(T_EQUALS);
        }

        node = new AST_BinOp(node, token, this->term());
    };

    return node;
};

/**
 * @deprecated
 *
 * @return AST*
 */
AST* Parser::program() {
    AST* node = this->compound_statement();
    this->eat(T_DOT);

    return node;
};

/**
 * This literally tries to parse anything.
 *
 * @return AST*
 */
AST* Parser::any_statement() {
    std::vector<AST*> nodes;

    nodes = this->statement_list();

    AST_Compound* root = new AST_Compound();

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        root->children.push_back((*it));

    return root;
};

/**
 * @return AST*
 */
AST* Parser::compound_statement() {
    std::vector<AST*> nodes;

    this->eat(T_BEGIN);
    nodes = this->statement_list();
    this->eat(T_END);

    AST_Compound* root = new AST_Compound();

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        root->children.push_back((*it));

    return root;
};

/**
 * @return std::vector<AST*>
 */
std::vector<AST*> Parser::statement_list() {
    std::vector<AST*> results;
    AST* node = this->statement();

    results.push_back(node);

    while (this->current_token->type == T_COLON) {
        this->eat(T_COLON);
        results.push_back(this->statement());
    }
    
    while (this->current_token->type == T_NEWLINE) {
        this->eat(T_NEWLINE);
        results.push_back(this->statement());
    }

    if (this->current_token->type == T_ID)
        this->error("Something bad happened");

    return results;
};

/**
 * Parses a single statement
 *
 * @return AST*
 */
AST* Parser::statement() {
    AST* node;

    if (this->current_token->type == T_FUNCTION_DEFINITION)
        return this->function_definition();
    else if (this->current_token->type == T_FUNCTION_CALL)
        return this->function_call();
    else if (this->current_token->type == T_ID)
        node = this->assignment_statement();
    else if (this->current_token->type == T_DECLARE)
        node = this->variable_declaration();
    else if (this->current_token->type == T_IF)
        node = this->if_statement();
    else if (this->current_token->type == T_DO)
        return this->do_while();
    else
        node = this->empty();

    return node;
};

/**
 * Parses a function call
 *
 * @return AST_FunctionCall*
 */
AST_FunctionCall* Parser::function_call() {
    std::vector<AST*> args;
    std::string function_name = this->current_token->value;

    this->eat(T_FUNCTION_CALL);
    this->eat(T_LPAREN);

    // if we encounter a RPAREN, we assume no arguments are specified
    // and we dont have to try and parse any arguments.
    // Because of this, functions are not required to have any arguments.
    if (this->current_token->type != T_RPAREN) {
        AST* node = this->expr();
        args.push_back(node);

        while(this->current_token->type == T_COMMA) {
            this->eat(T_COMMA);
            args.push_back(this->expr());
        }
    }
    
    this->eat(T_RPAREN);

    AST_FunctionCall* fc;
    AST_UserDefinedFunctionCall* udfc;

    if (function_name == "print") {
        fc = new AST_PrintCall(args);
        return fc;
    } else {
        udfc = new AST_UserDefinedFunctionCall(args, function_name);
        return udfc;
    }
    
    return nullptr;
};

/**
 * Parses a function definition
 *
 * @return AST_FunctionDefinition*
 */
AST_FunctionDefinition* Parser::function_definition() {
    std::vector<Token*> args;
    AST_Compound* body = new AST_Compound();
    std::vector<AST*> nodes;
    std::string function_name;

    this->eat(T_FUNCTION_DEFINITION);
    function_name = this->current_token->value;
    this->eat(T_ID);
    this->eat(T_LPAREN);

    // if we encounter a RPAREN, we assume no arguments are specified
    // and we dont have to try and parse any arguments.
    // Because of this, functions are not required to have any arguments.
    if (this->current_token->type != T_RPAREN) {
        args.push_back(this->current_token);
        this->eat(T_ID);

        while(this->current_token->type == T_COMMA) {
            this->eat(T_COMMA);
            args.push_back(this->current_token);
            this->eat(T_ID);
        }
    }
    
    this->eat(T_RPAREN);
    nodes = this->statement_list();
    this->eat(T_END);
    this->eat(T_FUNCTION_DEFINITION);

    Scope* scope = new Scope();
    body->scope = scope;
    
    // making sure all children of this function definition node are within
    // the same scope as the function definition node.
    for (std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        (*it)->scope = scope;

        // making sure the function calls arguments are in within the same
        // scope as the caller.
        if (dynamic_cast<AST_FunctionCall*>( (*it) )) {
            AST_FunctionCall* udfc = (AST_FunctionCall*)(*it);

            for (std::vector<AST*>::iterator it = udfc->args.begin(); it != udfc->args.end(); ++it)
                (*it)->scope = udfc->scope;
        }

        body->children.push_back((*it));
    }

    return new AST_FunctionDefinition(
        function_name,
        args,
        body
    );
};

/**
 * Parses an assign statement
 *
 * @return AST*
 */
AST* Parser::assignment_statement() {
    AST_Var* left = this->variable();
    Token* token = this->current_token;
    this->eat(T_ASSIGN);
    AST* right = this->expr();

    right->scope = left->scope;

    AST_Assign* node = new AST_Assign(left, token, right);

    return node;
};

/**
 * TODO: add documentation
 */
AST* Parser::if_statement() {
    std::vector<AST*> if_nodes;
    std::vector<AST_Else*> empty_else_vector;

    this->eat(T_IF);
    AST* if_expr = this->expr();
    this->eat(T_THEN);
    if_nodes = this->statement_list();

    AST_Compound* if_body = new AST_Compound();

    for(std::vector<AST*>::iterator it = if_nodes.begin(); it != if_nodes.end(); ++it)
        if_body->children.push_back((*it));

    std::vector<AST_Else*> elses;

    while (this->current_token->type == T_ELSE_IF) {
        this->eat(T_ELSE_IF);
        AST* else_expr = this->expr();
        this->eat(T_THEN);
        AST_Compound* else_body = new AST_Compound();
        std::vector<AST*> else_nodes = this->statement_list();
        for(std::vector<AST*>::iterator it = else_nodes.begin(); it != else_nodes.end(); ++it)
            else_body->children.push_back((*it));

        elses.push_back(new AST_Else(else_expr, else_body, empty_else_vector));
    }

    if (this->current_token->type == T_ELSE) {
        this->eat(T_ELSE);
        AST_Integer* else_expr = new AST_Integer(new Token(T_INTEGER, "1"));
        AST_Compound* else_body = new AST_Compound();
        std::vector<AST*> else_nodes = this->statement_list();
        for(std::vector<AST*>::iterator it = else_nodes.begin(); it != else_nodes.end(); ++it)
            else_body->children.push_back((*it));

        elses.push_back(new AST_Else(else_expr, else_body, empty_else_vector));
    }

    this->eat(T_END);
    this->eat(T_IF);
    
    AST_If* _if  = new AST_If(if_expr, if_body, elses);

    return _if;
};

AST_DoWhile* Parser::do_while() {
    AST* expr = nullptr;
    AST_Compound* body = new AST_Compound();
    std::vector<AST*> nodes;

    this->eat(T_DO);

    if (this->current_token->type == T_WHILE) {
        this->eat(T_WHILE);
        expr = this->expr();
        nodes = this->statement_list();
        this->eat(T_LOOP);
    } else {
        nodes = this->statement_list();
        this->eat(T_LOOP);
        this->eat(T_WHILE);
        expr = this->expr();
    }

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        body->children.push_back((*it));

    return new AST_DoWhile(expr, body);
};

/**
 * Parses the declaration of a variable
 *
 * @return AST*
 */
AST* Parser::variable_declaration() {
    std::vector<Token*> tokens;
    
    this->eat(T_DECLARE);

    tokens.push_back(this->current_token);
    this->eat(T_ID);

    while (this->current_token->type == T_COMMA) {
        this->eat(T_COMMA);
        tokens.push_back(this->current_token);
        this->eat(T_ID);
    }

    return new AST_VarDecl(tokens);
};

/**
 * Parses a variable
 *
 * @return AST_Var*
 */
AST_Var* Parser::variable() {
    AST_Var* node = new AST_Var(this->current_token);
    this->eat(T_ID);

    return node;
};

/**
 * Parses a none operation
 *
 * @return AST*
 */
AST* Parser::empty() {
    AST_NoOp* node = new AST_NoOp();

    return node;
};

/**
 * Parses everything, the main endpoint of the Parser.
 *
 * @return AST*
 */
AST* Parser::parse() {
    return this->any_statement();
};
