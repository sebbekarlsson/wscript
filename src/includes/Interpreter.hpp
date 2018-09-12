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

        int visit_BinOp(BinOp* node);
        int visit_UnaryOp(UnaryOp* node);
        int visit_Num(Num* node);
        int visit_Assign(Assign* node);
        int visit_Var(Var* node);
        int visit_Compound(Compound* node);
        int visit_NoOp(NoOp* node);
        int visit_VarDecl(VarDecl* node);
        int visit_If(If* node);
        int visit_functionCall(FunctionCall* node);
        int interpret();
};
#endif
