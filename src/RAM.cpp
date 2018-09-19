#include "includes/RAM.hpp"


std::map<std::string, anything> RAM::variables;

void RAM::set_variable(std::string key, anything value) {
    RAM::variables[key] = value;
};

anything RAM::get_variable(std::string key) {
    if (RAM::variables.find(key) == RAM::variables.end())
        throw std::runtime_error("Trying to access undefined variable: `" + key + "`");

    return RAM::variables[key];
};

bool RAM::has_variable(std::string key) {
    return RAM::variables.find(key) != RAM::variables.end();
};
