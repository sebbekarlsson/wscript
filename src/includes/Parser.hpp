#ifndef PARSER_H
#define PARSER_H
#include "Scope.hpp"
#include "Token.hpp"
#include "Lexer.hpp"
#include "AST/AST.hpp"
#include "AST/AST_Var.hpp"
#include "AST/AST_FunctionCall.hpp"
#include "AST/AST_FunctionDefinition.hpp"
#include "AST/AST_DoWhile.hpp"


class Parser {
    public:
        Parser(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);
        void error(std::string message);

        AST* factor(Scope* scope);
        AST* term(Scope* scope);
        AST* expr(Scope* scope);
        AST* program(Scope* scope);
        AST* any_statement(Scope* scope);
        AST* compound_statement(Scope* scope);
        std::vector<AST*> statement_list(Scope* scope);
        AST* statement(Scope* scope);
        AST* assignment_statement(Scope* scope);
        AST* if_statement(Scope* scope);
        AST_DoWhile* do_while(Scope* scope);
        AST* variable_declaration(Scope* scope);
        AST_Var* variable(Scope* scope);
        AST* empty(Scope* scope);
        AST_FunctionCall* function_call(Scope* scope);
        AST_FunctionDefinition* function_definition(Scope* scope);
        AST* parse();
};
#endif
