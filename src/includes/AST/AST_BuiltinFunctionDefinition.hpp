#ifndef AST_BUILT_IN_FUNCTIONDEFINITION_H
#define AST_BUILT_IN_FUNCTIONDEFINITION_H
#include "AST.hpp"
#include "AST_Compound.hpp"
#include "AST_Return.hpp"
#include <vector>
#include "../typedefs.hpp"
#include "../Token.hpp"


class Interpreter;

class AST_BuiltinFunctionDefinition: public AST {
    public:
        AST_BuiltinFunctionDefinition(std::string name);
        virtual ~AST_BuiltinFunctionDefinition()
        {}

        std::string name;
        
        std::vector<TokenType> expected_args;

        bool unlimited_args;
        
        virtual AST* call(std::vector<AST*> args, Interpreter* interpreter) = 0;
};
#endif
