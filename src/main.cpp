#include <iostream>
#include "includes/Interpreter.hpp"


int main(int argc, char** argv) {
    Interpreter* interpreter = new Interpreter("200+10");
    std::cout << interpreter->expr() << std::endl;
    return EXIT_SUCCESS;
}
