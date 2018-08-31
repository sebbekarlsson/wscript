#include <iostream>
#include "includes/TOKEN_TYPES.hpp"
#include "includes/Interpreter.hpp"


int main(int argc, char** argv) {
    Lexer* lexer = new Lexer(argv[1]);
    Interpreter* interpreter = new Interpreter(lexer);
    std::cout << interpreter->expr() << std::endl;
    return EXIT_SUCCESS;
}
