#ifndef AST_UBOUND_CALL_H
#define AST_UBOUND_CALL_H
#include "AST_FunctionCall.hpp"


class AST_UBoundCall: public AST_FunctionCall {
    public:
        AST_UBoundCall(std::vector<AST*> args);
        ~AST_UBoundCall();

        AST* call(Interpreter* interpreter);
};
#endif
