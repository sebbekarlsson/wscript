#ifndef AST_FUNCTIONDEFINITION_H
#define AST_FUNCTIONDEFINITION_H
#include "AST.hpp"
#include "AST_Compound.hpp"
#include "AST_Return.hpp"
#include <vector>
#include "../typedefs.hpp"
#include "../Token.hpp"


class Interpreter;

class AST_FunctionDefinition: public AST {
    public:
        AST_FunctionDefinition(std::string name, std::vector<Token*> args, AST_Compound* body);
        ~AST_FunctionDefinition();

        std::string name;
        std::vector<Token*> args;
        AST_Compound* body;
};
#endif
