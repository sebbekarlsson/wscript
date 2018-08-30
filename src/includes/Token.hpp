#ifndef TOKEN_H
#define TOKEN_H
#include <string>


class Token {
    public:
        Token(std::string type, std::string value);

        std::string type;
        std::string value;
};
#endif
