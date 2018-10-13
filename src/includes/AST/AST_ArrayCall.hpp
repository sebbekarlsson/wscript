#ifndef AST_ARRAY_CALL_H
#define AST_ARRAY_CALL_H
#include "AST_FunctionCall.hpp"


class AST_ArrayCall: public AST_FunctionCall {
    public:
        AST_ArrayCall(std::vector<AST*> args);
        ~AST_ArrayCall();

        AST* call(Interpreter* interpreter);
};
#endif
