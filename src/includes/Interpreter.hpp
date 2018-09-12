#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "NodeVisitor.hpp"
#include "Parser.hpp"
#include "RAM.hpp"


class Interpreter: public NodeVisitor {
    public:
        Interpreter(Parser* parser);

        Parser* parser;

        void error(std::string message);

        int visit_AST_BinOp(AST_BinOp* node);
        int visit_AST_UnaryOp(AST_UnaryOp* node);
        int visit_AST_Num(AST_Num* node);
        int visit_AST_Assign(AST_Assign* node);
        int visit_AST_Var(AST_Var* node);
        int visit_AST_Compound(AST_Compound* node);
        int visit_AST_NoOp(AST_NoOp* node);
        int visit_AST_VarDecl(AST_VarDecl* node);
        int visit_AST_If(AST_If* node);
        int visit_AST_functionCall(AST_FunctionCall* node);
        int interpret();
};
#endif
