#ifndef AST_ELSE_H
#define AST_ELSE_H
#include "AST.hpp"
#include "AST_Abstract_Condition.hpp"


class AST_Else: public AST_Abstract_Condition {
    public:
        AST_Else(AST* expr, AST* body, std::vector<AST_Else*> ast_elses);
        ~AST_Else();
};
#endif
