#include "includes/Num.hpp"


Num::Num(Token* token) {
    this->token = token;
    this->value = std::stoi(token->value);
};
