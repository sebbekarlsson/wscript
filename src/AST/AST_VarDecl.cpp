#include "../includes/AST/AST_VarDecl.hpp"


AST_VarDecl::AST_VarDecl(std::vector<Token*> tokens) {
    this->tokens = tokens;
};

AST_VarDecl::~AST_VarDecl() {};
