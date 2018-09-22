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
#include "includes/AST/AST_PrintCall.hpp"
#include "includes/AST/AST_UserDefinedFunctionCall.hpp"
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
extern std::string T_THEN;
extern std::string T_EOF;
extern std::string T_FUNCTION_CALL;
extern std::string T_FUNCTION_DEFINITION;
extern std::string T_COMMA;
extern std::string T_COLON;

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
        this->error("Expected token type: `" + token_type + "`, but got `" + this->current_token->type + "`");
    }
};

void Parser::error(std::string message) {
    throw std::runtime_error("[error][Parser](line=" + std::to_string(this->lexer->line) + ",pos=" + std::to_string(this->lexer->pos) + "): " + message);
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
 * @return std::string
 */
AST* Parser::term() {
    Token* token = nullptr;

    // we actually dont know if "this->factor()" will
    // return a BinOp* or a Num*.
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

        // we actually dont know if "this->factor()" will
        // return a BinOp* or a Num*.
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

AST* Parser::program() {
    AST* node = this->compound_statement();
    this->eat(T_DOT);

    return node;
};

AST* Parser::any_statement() {
    std::vector<AST*> nodes;

    nodes = this->statement_list();

    AST_Compound* root = new AST_Compound();

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

    AST_Compound* root = new AST_Compound();

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        root->children.push_back((*it));
    }

    return root;
};

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

    if (this->current_token->type == T_ID) {
        this->error("Something bad happened");
    }

    return results;
};

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
    else
        node = this->empty();

    return node;
};

AST_FunctionCall* Parser::function_call() {
    std::vector<AST*> args;
    std::string function_name = this->current_token->value;

    this->eat(T_FUNCTION_CALL);
    this->eat(T_LPAREN);

    AST* node = this->expr();
    args.push_back(node);

    while(this->current_token->type == T_COMMA) {
        this->eat(T_COMMA);
        args.push_back(this->expr());
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

AST_FunctionDefinition* Parser::function_definition() {
    std::vector<Token*> args;
    AST_Compound* body = new AST_Compound();
    std::vector<AST*> nodes;
    std::string function_name;

    this->eat(T_FUNCTION_DEFINITION);
    function_name = this->current_token->value;
    this->eat(T_ID);
    this->eat(T_LPAREN);

    args.push_back(this->current_token);
    this->eat(T_ID);

    while(this->current_token->type == T_COMMA) {
        this->eat(T_COMMA);
        args.push_back(this->current_token);
        this->eat(T_ID);
    }
    
    this->eat(T_RPAREN);
    nodes = this->statement_list();
    this->eat(T_END);
    this->eat(T_FUNCTION_DEFINITION);
    
    for (std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        body->children.push_back((*it));
    }

    AST_FunctionDefinition* fd = new AST_FunctionDefinition(
        function_name,
        args,
        body
    );

    return fd;
};

AST* Parser::assignment_statement() {
    AST_Var* left = this->variable();
    Token* token = this->current_token;
    this->eat(T_ASSIGN);
    AST* right = this->expr();
    AST_Assign* node = new AST_Assign(left, token, right);

    return node;
};

AST* Parser::if_statement() {
    std::vector<AST*> nodes;

    this->eat(T_IF);
    AST* node = this->expr();
    this->eat(T_THEN);
    nodes = this->statement_list();

    AST_Compound* root = new AST_Compound();

    for(std::vector<AST*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
        root->children.push_back((*it));
    }

    this->eat(T_END);
    this->eat(T_IF);
    
    AST_If* _if  = new AST_If(node, root);

    return _if;
};

AST* Parser::variable_declaration() {
    AST_VarDecl* decl;
    std::vector<Token*> tokens;
    
    this->eat(T_DECLARE);

    tokens.push_back(this->current_token);
    this->eat(T_ID);

    while (this->current_token->type == T_COMMA) {
        this->eat(T_COMMA);
        tokens.push_back(this->current_token);
        this->eat(T_ID);
    }

    decl = new AST_VarDecl(tokens);

    return decl;
};

AST_Var* Parser::variable() {
    AST_Var* node = new AST_Var(this->current_token);
    this->eat(T_ID);

    return node;
};

AST* Parser::empty() {
    AST_NoOp* node = new AST_NoOp();

    return node;
};

AST* Parser::parse() {
    AST* node = this->any_statement();

    //if (this->current_token->type != T_EOF)
    //    throw std::runtime_error("Expected EOF");

    return node;
};
