#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "NodeVisitor.hpp"
#include "Parser.hpp"


class Interpreter: public NodeVisitor {
    public:
        Interpreter(Parser* parser);

        Parser* parser;

        void error(std::string message);

        /* visit methods */

        anything visit_AST_BinOp(AST_BinOp* node);
        anything visit_AST_UnaryOp(AST_UnaryOp* node);
        anything visit_AST_Assign(AST_Assign* node);
        anything visit_AST_Var(AST_Var* node);
        anything visit_AST_functionCall(AST_FunctionCall* node);
        anything visit_AST_functionDefinition(AST_FunctionDefinition* node);
        anything visit_AST_Return(AST_Return* node);
        anything visit_AST_AttributeAccess(AST_AttributeAccess* node);
        anything visit_AST_ArrayAccess(AST_ArrayAccess* node);
        anything visit_AST_Array(AST_Array* node);

        AST_Object* visit_AST_Object(AST_Object* node);
        AST_Empty* visit_AST_Empty(AST_Empty* node);

        int visit_AST_Integer(AST_Integer* node);
        int visit_AST_Compound(AST_Compound* node);
        int visit_AST_NoOp(AST_NoOp* node);
        int visit_AST_VarDecl(AST_VarDecl* node);
        int visit_AST_Abstract_Condition(AST_Abstract_Condition* node);
        int visit_AST_DoWhile(AST_DoWhile* node);

        float visit_AST_Float(AST_Float* node);

        std::string visit_AST_Str(AST_Str* node);

        char visit_AST_StringAccess(AST_StringAccess* node);

        /* operation methods */

        anything operation(anything left, TokenType op, anything right);
        anything operation(AST* left, TokenType op, AST* right);
        anything operation(float left, TokenType op, float right);
        anything operation(float left, TokenType op, std::string right);
        anything operation(std::string left, TokenType op, std::string right);
        anything operation(std::string left, TokenType op, int right);
        anything operation(std::string left, TokenType op, float right);
        anything operation(int left, TokenType op, std::string right);
        anything operation(int left, TokenType op, int right);

        anything unary_operation(TokenType op, anything right);
        anything unary_operation(TokenType op, int right);
        anything unary_operation(TokenType op, float right);
        anything unary_operation(TokenType op, std::string right);

        anything interpret();
};
#endif
