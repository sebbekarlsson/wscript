#ifndef AST_FUNCTIONCALL_H
#define AST_FUNCTIONCALL_H
#include "AST.hpp"
#include <vector>


class AST_FunctionCall: public AST {
    public:
        AST_FunctionCall(std::vector<AST*> args);

        std::vector<AST*> args;

        virtual AST* call(std::vector<int> call_args) = 0;
};
#endif
