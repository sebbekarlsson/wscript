#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "NodeVisitor.hpp"
#include "Parser.hpp"


class Interpreter: public NodeVisitor {
    public:
        Interpreter(Parser* parser);

        Parser* parser;

        int visit_BinOp(BinOp* node);
        int visit_UnaryOp(UnaryOp* node);
        int visit_Num(Num* node);
        std::string interpret();
};
#endif
