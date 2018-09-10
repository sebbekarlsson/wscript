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
std::string T_DATE = "DATE";
std::string T_STRING = "STRING";
std::string T_OBJECT = "OBJECT";
std::string T_ARRAY = "ARRAY";
std::string T_EMPTY = "EMPTY";
std::string T_NULL = "NULL";
std::string T_LPAREN = "(";
std::string T_RPAREN = ")";
std::string T_DOT = "DOT";
std::string T_SEMI = "SEMI";
std::string T_ASSIGN = "ASSIGN";
std::string T_ID = "ID";
std::string T_BEGIN = "BEGIN";
std::string T_DECLARE = "DECLARE";
std::string T_COMMA = "COMMA";
std::string T_NEWLINE = "NEWLINE";
std::string T_IF = "IF";
std::string T_THEN = "THEN";
std::string T_LARGER_THAN = "LARGER_THAN";
std::string T_LESS_THAN = "LESS_THAN";
std::string T_END = "END";
std::string T_EOF = "EOF";

std::map<std::string, std::string> RESERVED_KEYWORDS = {
    {"BEGIN", T_BEGIN},
    {"End", T_END},
    {"Dim", T_DECLARE},
    {"If", T_IF},
    {"Then", T_THEN}
};
#endif
