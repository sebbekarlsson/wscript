#ifndef COUTPRINT_HPP
#define COUTPRINT_HPP
#include "typedefs.hpp"
#include <iostream>
#include "AST/AST.hpp"


void coutprint(anything value);

void coutprint(std::string value);

void coutprint(int value);

void coutprint(float value);

void coutprint(bool value);

void coutprint(AST* value);
#endif
