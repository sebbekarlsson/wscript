#include "includes/RAM.hpp"


std::map<std::string, std::string> RAM::variables;

void RAM::set_variable(std::string key, std::string value) {
    RAM::variables[key] = value;
};

std::string RAM::get_variable(std::string key) {
    if (RAM::variables.find(key) == RAM::variables.end())
        throw std::runtime_error("Trying to access undefined variable: `" + key + "`");

    return RAM::variables[key];
};
