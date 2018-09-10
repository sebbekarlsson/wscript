#include <iostream>
#include <ResourceManager.h>
#include "includes/TOKEN_TYPES.hpp"
#include "includes/Parser.hpp"
#include "includes/Interpreter.hpp"


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "no input file" << std::endl;
        
        return EXIT_FAILURE;
    }

    ResourceManager::load(argv[1]);

    Lexer* lexer = new Lexer(ResourceManager::get(argv[1]));
    Parser* parser = new Parser(lexer);
    Interpreter* interpreter = new Interpreter(parser);

    interpreter->interpret();

    return EXIT_SUCCESS;
}
