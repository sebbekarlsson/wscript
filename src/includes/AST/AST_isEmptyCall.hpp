#ifndef AST_IS_EMPTY_CALL_H
#define AST_IS_EMPTY_CALL_H
#include "AST_FunctionCall.hpp"


class AST_isEmptyCall: public AST_FunctionCall {
    public:
        AST_isEmptyCall(std::vector<AST*> args);
        ~AST_isEmptyCall();

        AST* call(Interpreter* interpreter);
};
#endif
