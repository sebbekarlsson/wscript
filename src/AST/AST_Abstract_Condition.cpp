#include "../includes/AST/AST_Abstract_Condition.hpp"
#include "../includes/AST/AST_Else.hpp"


AST_Abstract_Condition::AST_Abstract_Condition(AST* expr, AST* body, std::vector<AST_Else*> ast_elses) : AST() {
    this->expr = expr;
    this->body = body;
    this->ast_elses = ast_elses;
};
