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
        Scope* private_scope = nullptr;
        //Scope* parent_scope = nullptr;

        Scope* get_scope();
        Scope* get_private_scope();
        //Scope* get_parent_scope();
};
#endif
