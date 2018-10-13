#ifndef AST_FUNCTIONCALL_H
#define AST_FUNCTIONCALL_H
#include "AST.hpp"
#include <vector>


class Interpreter;

class AST_FunctionCall: public AST {
    public:
        AST_FunctionCall(std::vector<AST*> args);
        virtual ~AST_FunctionCall()
        {}

        std::vector<AST*> args;

        virtual AST* call(Interpreter* interpreter) = 0;
};
#endif
