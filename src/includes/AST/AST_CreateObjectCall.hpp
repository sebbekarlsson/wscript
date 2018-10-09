#ifndef AST_CREATE_OBJECT_CALL_H
#define AST_CREATE_OBJECT_CALL_H
#include "AST_FunctionCall.hpp"


class AST_CreateObjectCall: public AST_FunctionCall {
    public:
        AST_CreateObjectCall(std::vector<AST*> args);
        ~AST_CreateObjectCall();

        AST* call(Interpreter* interpreter);
};
#endif
