#ifndef AST_USER_DEFINED_FUNCTIONCALL_H
#define AST_USER_DEFINED_FUNCTIONCALL_H
#include "AST.hpp"
#include "AST_FunctionCall.hpp"
#include "AST_FunctionDefinition.hpp"
#include <vector>
#include "../typedefs.hpp"


class Interpreter;

class AST_UserDefinedFunctionCall: public AST_FunctionCall {
    public:
        AST_UserDefinedFunctionCall(std::vector<AST*> args, AST_FunctionDefinition* definition);
        ~AST_UserDefinedFunctionCall();

        AST_FunctionDefinition* definition;

        AST* call(Interpreter* interpreter);
};
#endif
