#include "../includes/AST/AST_Else.hpp"


AST_Else::AST_Else(AST* expr, AST* body, std::vector<AST_Else*> ast_elses) : AST_Abstract_Condition(expr, body, ast_elses) {};

AST_Else::~AST_Else() {};
