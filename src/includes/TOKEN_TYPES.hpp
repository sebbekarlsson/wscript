#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H
#include <string>
// https://www.promotic.eu/en/pmdoc/ScriptLangs/VBScript/DataTypes.htm

std::string T_INTEGER = "INTEGER";
std::string T_PLUS = "PLUS";
std::string T_MINUS = "MINUS";
std::string T_MULTIPLY = "MULTIPLY";
std::string T_DIVIDE = "DIVIDE";
std::string T_BOOLEAN = "BOOLEAN";
std::string T_BYTE = "BYTE";
std::string T_LONG = "LONG";
std::string T_SINGLE = "SINGLE";
std::string T_DOUBLE = "DOUBLE";
std::string T_FLOAT = "FLOAT";
std::string T_DATE = "DATE";
std::string T_STRING = "STRING";
std::string T_OBJECT = "OBJECT";
std::string T_ARRAY = "ARRAY";
std::string T_EMPTY = "EMPTY";
std::string T_NULL = "NULL";
std::string T_LPAREN = "LPAREN";
std::string T_RPAREN = "RPAREN";
std::string T_DOT = "DOT";
std::string T_ATTRIBUTE = "ATTRIBUTE";
std::string T_AS = "AS";
std::string T_SEMI = "SEMI";
std::string T_ASSIGN = "ASSIGN";
std::string T_ID = "ID";
std::string T_BEGIN = "BEGIN";
std::string T_DECLARE = "DECLARE";
std::string T_COMMA = "COMMA";
std::string T_NEWLINE = "NEWLINE";
std::string T_IF = "IF";
std::string T_ELSE = "ELSE";
std::string T_ELSE_IF = "ELSE_IF";
std::string T_THEN = "THEN";
std::string T_LARGER_THAN = "LARGER_THAN";
std::string T_LESS_THAN = "LESS_THAN";
std::string T_LARGER_OR_EQUALS = "LARGER_OR_EQUALS";
std::string T_LESS_OR_EQUALS = "LESS_OR_EQUALS";
std::string T_NOT_EQUALS = "NOT_EQUALS";
std::string T_EQUALS = "EQUALS";
std::string T_END = "END";
std::string T_EOF = "EOF";
std::string T_FUNCTION_CALL = "FUNCTION_CALL";
std::string T_FUNCTION_DEFINITION = "FUNCTION_DEFINITION";
std::string T_DO = "DO";
std::string T_WHILE = "WHILE";
std::string T_LOOP = "LOOP";
std::string T_COLON = "COLON";

std::map<std::string, std::string> RESERVED_KEYWORDS = {
    {"BEGIN", T_BEGIN},
    {"End", T_END},
    {"Dim", T_DECLARE},
    {"If", T_IF},
    {"Else", T_ELSE},
    {"ElseIf", T_ELSE_IF},
    {"Then", T_THEN},
    {"Function", T_FUNCTION_DEFINITION},
    {"Do", T_DO},
    {"Loop", T_LOOP},
    {"While", T_WHILE},
    {"As", T_AS},
    {"print", T_FUNCTION_CALL},
    {"WScript", T_OBJECT},
    {"CreateObject", T_FUNCTION_CALL}
};
#endif
