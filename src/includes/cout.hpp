#ifndef COUTPRINT_HPP
#define COUTPRINT_HPP
#include "typedefs.hpp"
#include <iostream>
#include "AST/AST.hpp"
#include "AST/AST_Array.hpp"


void coutprint(anything value);

void coutprint(std::string value);

void coutprint_char(char value);

void coutprint(float value);

void coutprint(bool value);

void coutprint(AST* value);

void coutprint(AST_Array* value);

void coutprint(int value);
#endif
