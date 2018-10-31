#include "../includes/AST/AST_Function_Array.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/typedefs.hpp"
#include <iostream>


AST_Function_Array::AST_Function_Array(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->expected_args.push_back(TokenType::String);
}

AST_Function_Array::~AST_Function_Array() {
};

AST* AST_Function_Array::call(std::vector<AST*> args, Interpreter* interpreter) {
    AST_Array* arr = new AST_Array(nullptr);

    for (std::vector<AST*>::iterator it = args.begin(); it != args.end(); ++it)
        arr->items.push_back(interpreter->visit((*it)));

    return arr;
};
