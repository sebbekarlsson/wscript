#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "NodeVisitor.hpp"
#include "Parser.hpp"


class Interpreter: public NodeVisitor {
    public:
        Interpreter(Parser* parser);

        Parser* parser;

        std::string visit_BinOp(BinOp* node);
        std::string visit_Num(Num* node);
        std::string interpret();
};
#endif
