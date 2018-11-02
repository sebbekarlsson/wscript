#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H
#include "TokenType.hpp"
#include <string>
#include <map>
// https://www.promotic.eu/en/pmdoc/ScriptLangs/VBScript/DataTypes.htm

std::map<std::string, TokenType> RESERVED_KEYWORDS = {
    {"end", TokenType::End},
    {"dim", TokenType::Declare},
    {"if", TokenType::If},
    {"else", TokenType::Else},
    {"elseif", TokenType::Else_if},
    {"then", TokenType::Then},
    {"function", TokenType::Function_definition},
    {"do", TokenType::Do},
    {"loop", TokenType::Loop},
    {"while", TokenType::While},
    {"empty", TokenType::Empty},
    {"as", TokenType::As},
    {"print", TokenType::Function_call},
    {"wscript", TokenType::Object},
    {"createobject", TokenType::Function_call},
    {"array", TokenType::Function_call},
    {"ubound", TokenType::Function_call},
    {"split", TokenType::Function_call},
    {"isempty", TokenType::Function_call}
};
#endif
