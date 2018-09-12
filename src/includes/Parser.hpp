#ifndef PARSER_H
#define PARSER_H
#include "Token.hpp"
#include "Lexer.hpp"
#include "AST/AST.hpp"
#include "AST/AST_Var.hpp"
#include "AST/AST_FunctionCall.hpp"


class Parser {
    public:
        Parser(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);
        void error(std::string message);

        AST* factor();
        AST* term();
        AST* expr();
        AST* program();
        AST* any_statement();
        AST* compound_statement();
        std::vector<AST*> statement_list();
        AST* statement();
        AST* assignment_statement();
        AST* if_statement();
        AST* variable_declaration();
        AST_Var* variable();
        AST* empty();
        AST_FunctionCall* function_call();
        AST* parse();
};
#endif
