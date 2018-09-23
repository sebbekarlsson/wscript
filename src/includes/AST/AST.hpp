#ifndef AST_H
#define AST_H
#include <string>


class Scope;

class AST {
    public:
        AST();
        virtual ~AST()
        {}

        Scope* scope = nullptr;

        Scope* get_scope();
};
#endif
