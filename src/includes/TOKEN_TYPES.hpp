#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H
#include "TokenType.hpp"
#include <string>
#include <map>
// https://www.promotic.eu/en/pmdoc/ScriptLangs/VBScript/DataTypes.htm

std::map<std::string, TokenType> RESERVED_KEYWORDS = {
    {"BEGIN", TokenType::Begin},
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
    {"print", TokenType::Function_call},
    {"WScript", TokenType::Object},
    {"CreateObject", TokenType::Function_call},
    {"Array", TokenType::Function_call},
    {"UBound", TokenType::Function_call},
    {"Split", TokenType::Function_call},
    {"isEmpty", TokenType::Function_call}
};
#endif
