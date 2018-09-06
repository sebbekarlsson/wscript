#include <iostream>
#include <ResourceManager.h>
#include "includes/TOKEN_TYPES.hpp"
#include "includes/Parser.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "no input file" << std::endl;
        
        return EXIT_FAILURE;
    }

    ResourceManager::load(argv[1]);

    Lexer* lexer = new Lexer(ResourceManager::get(argv[1]));
    Parser* interpreter = new Parser(lexer);

    std::cout << interpreter->expr() << std::endl;

    return EXIT_SUCCESS;
}
