#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H
#include "TokenType.hpp"
#include <string>
#include <map>
// https://www.promotic.eu/en/pmdoc/ScriptLangs/VBScript/DataTypes.htm

std::map<std::string, TokenType> RESERVED_KEYWORDS = {
    {"End", TokenType::End},
    {"Dim", TokenType::Declare},
    {"If", TokenType::If},
    {"Else", TokenType::Else},
    {"ElseIf", TokenType::Else_if},
    {"Then", TokenType::Then},
    {"Function", TokenType::Function_definition},
    {"Do", TokenType::Do},
    {"Loop", TokenType::Loop},
    {"While", TokenType::While},
    {"Empty", TokenType::Empty},
    {"As", TokenType::As},
    {"WScript", TokenType::Object}
};
#endif
