#ifndef PRINTCALL_H
#define PRINTCALL_H
#include "FunctionCall.hpp"


class PrintCall: public FunctionCall {
    public:
        PrintCall(std::vector<AST*> args);

        AST* call(std::vector<int> call_args);
};
#endif
