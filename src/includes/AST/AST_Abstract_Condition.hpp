#ifndef AST_ABSTRACT_CONDITION_H
#define AST_ABSTRACT_CONDITION_H
#include "AST.hpp"
#include <vector>


class AST_Else;

class AST_Abstract_Condition: public AST {
    public:
        AST_Abstract_Condition(AST* expr, AST* body, std::vector<AST_Else*> ast_elses);
        virtual ~AST_Abstract_Condition()
        {};

        AST* expr;
        AST* body;
        std::vector<AST_Else*> ast_elses;
};
#endif
