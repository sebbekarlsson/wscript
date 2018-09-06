#include "includes/Num.hpp"


Num::Num(Token* token) {
    this->token = token;
    this->value = token->value;
};
