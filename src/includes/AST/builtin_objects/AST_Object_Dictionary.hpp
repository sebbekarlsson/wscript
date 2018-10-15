#ifndef AST_OBJECT_DICT_H
#define AST_OBJECT_DICT_H
#include "../AST_Object.hpp"
#include "AST_Object_Dictionary_Add.hpp"
#include "AST_Object_Dictionary_Exists.hpp"


class AST_Object_Dictionary: public AST_Object {
    public:
        AST_Object_Dictionary(Token* token);
        ~AST_Object_Dictionary();

        Token* token;
};
#endif
