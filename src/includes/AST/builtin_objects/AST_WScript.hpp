#ifndef AST_WSCRIPT_OBJECT_H
#define AST_WSCRIPT_OBJECT_H
#include "../AST_Object.hpp"
#include "AST_WScript_Echo.hpp"
#include <string>


class AST_WScript: public AST_Object {
    public:
        AST_WScript(Token* token);
        ~AST_WScript();
};
#endif
