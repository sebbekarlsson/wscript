#ifndef AST_SPLIT_CALL_H
#define AST_SPLIT_CALL_H
#include "AST_FunctionCall.hpp"


class AST_SplitCall: public AST_FunctionCall {
    public:
        AST_SplitCall(std::vector<AST*> args);
        ~AST_SplitCall();

        AST* call(Interpreter* interpreter);
};
#endif
