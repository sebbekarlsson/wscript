#ifndef AST_OBJECT_CUSTOM_H
#define AST_OBJECT_CUSTOM_H
#include "AST_Object.hpp"
#include "../Token.hpp"


class AST_ObjectCustom: public AST_Object {
    public:
        AST_ObjectCustom(Token* token);
        virtual ~AST_ObjectCustom() {};

        typedef AST_ObjectCustom * create_t(int);
        typedef void destroy_t(AST_ObjectCustom*);
};
#endif
