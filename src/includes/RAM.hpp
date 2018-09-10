#ifndef RAMZ_H
#define RAMZ_H
#include <string>
#include <map>


class RAM {
    public:
        static void set_variable(std::string key, std::string value);

        static std::string get_variable(std::string key);

        static bool has_variable(std::string key);

    private:
        static std::map<std::string, std::string> variables;
};
#endif
