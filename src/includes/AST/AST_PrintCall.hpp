#ifndef AST_PRINTCALL_H
#define AST_PRINTCALL_H
#include "AST_FunctionCall.hpp"
#include "../cout.hpp"


class AST_PrintCall: public AST_FunctionCall {
    public:
        AST_PrintCall(std::vector<AST*> args);
        ~AST_PrintCall();

        AST* call(Interpreter* interpreter);
};
#endif
