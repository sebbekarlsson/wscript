#ifndef AST_PRINTCALL_H
#define AST_PRINTCALL_H
#include "AST_FunctionCall.hpp"


class AST_PrintCall: public AST_FunctionCall {
    public:
        AST_PrintCall(std::vector<AST*> args);

        AST* call(std::vector<int> call_args);
};
#endif
