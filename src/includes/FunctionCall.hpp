#ifndef FUNCTIONCALL_H
#define FUNCTIONCALL_H
#include "AST.hpp"
#include <vector>


class FunctionCall: public AST {
    public:
        FunctionCall(std::vector<AST*> args);

        std::vector<AST*> args;

        virtual AST* call(std::vector<int> call_args) = 0;
};
#endif
