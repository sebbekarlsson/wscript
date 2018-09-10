#ifndef PARSER_H
#define PARSER_H
#include "Token.hpp"
#include "Lexer.hpp"
#include "AST.hpp"
#include "Var.hpp"


class Parser {
    public:
        Parser(Lexer* lexer);

        Lexer* lexer;
        Token* current_token;

        void eat(std::string token_type);

        AST* factor();
        AST* term();
        AST* expr();
        AST* program();
        AST* compound_statement();
        std::vector<AST*> statement_list();
        AST* statement();
        AST* assignment_statement();
        AST* variable_declaration();
        Var* variable();
        AST* empty();
        AST* parse();
};
#endif
