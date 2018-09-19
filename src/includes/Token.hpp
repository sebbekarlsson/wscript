#ifndef TOKEN_H
#define TOKEN_H
#include <string>


class Token {
    public:
        Token(std::string type, std::string value);

        std::string type;
        std::string value;

        std::string get_string();

        int get_integer();

        float get_float();
};
#endif
