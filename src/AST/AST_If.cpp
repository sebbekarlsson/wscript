#include "../includes/AST/AST_If.hpp"


AST_If::AST_If(AST* expr, AST* body, std::vector<AST_Else*> ast_elses) : AST_Abstract_Condition(expr, body, ast_elses) {};

AST_If::~AST_If() {};
