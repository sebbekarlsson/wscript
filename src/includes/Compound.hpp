#ifndef COMPUND_H
#define COMPUND_H
#include "AST.hpp"
#include "Token.hpp"
#include <vector>


class Compound: public AST {
    public:
        Compound();

        std::vector<AST*> children;
};
#endif
