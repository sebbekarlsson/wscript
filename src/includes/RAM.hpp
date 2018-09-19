#ifndef RAMZ_H
#define RAMZ_H
#include <string>
#include <map>
#include "typedefs.hpp"


class RAM {
    public:
        static void set_variable(std::string key, anything);

        static anything get_variable(std::string key);

        static bool has_variable(std::string key);

    private:
        static std::map<std::string, anything> variables;
};
#endif
