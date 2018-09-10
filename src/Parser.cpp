#include "includes/Parser.hpp"
#include "includes/Num.hpp"
#include "includes/BinOp.hpp"
#include "includes/UnaryOp.hpp"
#include "includes/NoOp.hpp"
#include "includes/Compound.hpp"
#include "includes/Var.hpp"
#include "includes/Assign.hpp"
#include "includes/VarDecl.hpp"
#include "includes/If.hpp"
#include <ctype.h>
#include <iostream>
#include <sstream>


extern std::string T_INTEGER;
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
extern std::string T_IF;
extern std::string T_THEN;
extern std::string T_EOF;

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
    if (this->current_token->type == token_type) {
        this->current_token = this->lexer->get_next_token();
    } else {
        throw std::runtime_error("Expected token type: `" + token_type + "`, but got `" + this->current_token->type + "`");
    }
};

/**
 * executes the Parser::eats method with T_INTEGER
 * and returns the current_token->value that was before `eat` was executed.
 * factor: INTEGER
 * 
 * @return std::string
 */
AST* Parser::factor() {
    Token* token = this->current_token;

    if (token->type == T_PLUS) {
        this->eat(T_PLUS);
        UnaryOp* node = new UnaryOp(token, this->factor());
        node->name = "UnaryOp";
        return node;

    } else if (token->type == T_MINUS) {
        this->eat(T_MINUS);
        UnaryOp* node = new UnaryOp(token, this->factor());
        node->name = "UnaryOp";
        return node;

    } else if (token->type == T_INTEGER) {
        this->eat(T_INTEGER);
        Num* num = new Num(token);
        num->name = "Num";

        return num;
    } else if (token->type == T_LPAREN) {
        this->eat(T_LPAREN);
        AST* node = this->expr();
        this->eat(T_RPAREN);
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
 * @return std::string
 */
AST* Parser::term() {
    Token* token = nullptr;

    // we actually dont know if "this->factor()" will
    // return a BinOp* or a Num*.
    AST* node = this->factor();
    
    if (node->name == "BinOp") {
        node = (BinOp*) node;
    } else if (node->name == "Num") {
        node = (Num*) node;
    }

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

        // we actually dont know if "this->factor()" will
        // return a BinOp* or a Num*.
        node = new BinOp(node, token, this->factor());
        node->name = "BinOp";
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
    
    if (node->name == "BinOp") {
        node = (BinOp*) node;
    } else if (node->name == "Num") {
        node = (Num*) node;
    }

    while(
        this->current_token->type == T_PLUS ||
        this->current_token->type == T_MINUS
    ) {
        token = this->current_token;

        if (token->type == T_PLUS) {
            this->eat(T_PLUS);
        } else if (token->type == T_MINUS) {
            this->eat(T_MINUS);
        }

        node = new BinOp(node, token, this->term());
        node->name = "BinOp";
    };

    return node;
};

AST* Parser::program() {
    AST* node = this->compound_statement();
    this->eat(T_DOT);

    return node;
};

AST* Parser::any_statement() {
    std::vector<AST*> nodes;

    nodes = this->statement_list();

    Compound* root = new Compound();
    root->name = "Compound";

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        root->children.push_back((*it));
    }

    return root;
};

AST* Parser::compound_statement() {
    std::vector<AST*> nodes;

    this->eat(T_BEGIN);
    nodes = this->statement_list();
    this->eat(T_END);

    Compound* root = new Compound();
    root->name = "Compound";

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        root->children.push_back((*it));
    }

    return root;
};

std::vector<AST*> Parser::statement_list() {
    std::vector<AST*> results;
    AST* node = this->statement();

    results.push_back(node);

    while (this->current_token->type == T_NEWLINE) {
        this->eat(T_NEWLINE);
        results.push_back(this->statement());
    }

    if (this->current_token->type == T_ID) {
        throw std::runtime_error("Something bad happened");
    }

    return results;
};

AST* Parser::statement() {
    AST* node;

    if (this->current_token->type == T_BEGIN)
        node = this->compound_statement();
    else if (this->current_token->type == T_ID)
        node = this->assignment_statement();
    else if (this->current_token->type == T_DECLARE)
        node = this->variable_declaration();
    else if (this->current_token->type == T_IF)
        node = this->if_statement();
    else
        node = this->empty();

    return node;
};

AST* Parser::assignment_statement() {
    Var* left = this->variable();
    Token* token = this->current_token;
    this->eat(T_ASSIGN);
    AST* right = this->expr();
    Assign* node = new Assign(left, token, right);
    node->name = "Assign";

    return node;
};

AST* Parser::if_statement() {
    std::vector<AST*> nodes;

    this->eat(T_IF);
    Comparison* comp = this->comparison();
    this->eat(T_THEN);
    nodes = this->statement_list();

    Compound* root = new Compound();
    root->name = "Compound";

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        root->children.push_back((*it));
    }

    this->eat(T_END);
    this->eat(T_IF);
    
    If* _if  = new If(comp, root);
    _if->name = "If";

    return _if;
};

AST* Parser::variable_declaration() {
    VarDecl* decl;
    
    this->eat(T_DECLARE);
    decl = new VarDecl(this->current_token);
    decl->name = "VarDecl";
    this->eat(T_ID);

    return decl;
};

Var* Parser::variable() {
    Var* node = new Var(this->current_token);
    node->name = "Var";
    this->eat(T_ID);

    return node;
};

AST* Parser::empty() {
    NoOp* node = new NoOp();
    node->name = "NoOp";

    return node;
};

Comparison* Parser::comparison() {
    AST* left = this->expr();
    Token* token = this->current_token;

    if (this->current_token->type == T_LARGER_THAN)
        this->eat(T_LARGER_THAN);
    else if (this->current_token->type == T_LESS_THAN)
        this->eat(T_LESS_THAN);
    else
        throw std::runtime_error("Unknown comparison with: `" + this->current_token->type + "`");

    AST* right = this->expr();

    Comparison* comp = new Comparison(left, token, right);
    comp->name = "Comparison";

    return comp;
};

AST* Parser::parse() {
    AST* node = this->any_statement();

    //if (this->current_token->type != T_EOF)
    //    throw std::runtime_error("Expected EOF");

    return node;
};
