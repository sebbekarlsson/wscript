#ifndef AST_STRING_ACCESS_H
#define AST_STRING_ACCESS_H
#include <vector>
#include <string>
#include "AST.hpp"


class AST_StringAccess: public AST {
    public:
        AST_StringAccess(std::string value, std::vector<AST*> args);
        ~AST_StringAccess();

        std::string value;
        std::vector<AST*> args;
};
#endif
