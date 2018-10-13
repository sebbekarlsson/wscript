#include "../includes/AST/AST_Array.hpp"
#include "../includes/memory_utils.hpp"


AST_Array::AST_Array(Token* token) {
    this->token = token;
};

AST_Array::~AST_Array() {
    free_vector(this->items);
};
