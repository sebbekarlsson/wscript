#ifndef AST_OBJECT_WSCRIPT_H
#define AST_OBJECT_WSCRIPT_H
#include "../AST_Object.hpp"
#include "AST_WScript_Echo.hpp"
#include <string>


class AST_WScript: public AST_Object {
    public:
        AST_WScript();
        ~AST_WScript();
};
#endif
