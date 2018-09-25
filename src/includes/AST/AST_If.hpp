#ifndef AST_IF_H
#define AST_IF_H
#include "AST.hpp"
#include "AST_Abstract_Condition.hpp"


class AST_If: public AST_Abstract_Condition {
    public:
        AST_If(AST* expr, AST* body, std::vector<AST_Else*> ast_elses);
        ~AST_If();
};
#endif
