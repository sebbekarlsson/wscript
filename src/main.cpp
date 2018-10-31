#include <iostream>
#include <ResourceManager.h>
#include "includes/TOKEN_TYPES.hpp"
#include "includes/Parser.hpp"
#include "includes/Interpreter.hpp"
#include "includes/Scope.hpp"
#include "includes/initialize_scope.hpp"


Scope* global_scope;

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "no input file" << std::endl;
        
        return EXIT_FAILURE;
    }

    ResourceManager::load(argv[1]);

    global_scope = new Scope("global");
    initialize_scope(global_scope);

    Lexer* lexer = new Lexer(ResourceManager::get(argv[1]));
    Parser* parser = new Parser(lexer);
    Interpreter* interpreter = new Interpreter(parser);

    interpreter->interpret();

    ResourceManager::unload(argv[1]);

    delete interpreter;
    delete global_scope;

    return EXIT_SUCCESS;
}
