#include "../includes/AST/AST_Function_Split.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/typedefs.hpp"
#include <iostream>


AST_Function_Split::AST_Function_Split(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->expected_args.push_back(TokenType::String);
}

AST_Function_Split::~AST_Function_Split() {
};

AST* AST_Function_Split::call(std::vector<AST*> args, Interpreter* interpreter) {
    if (args.size() == 0)
        return new AST_NoOp();

    anything var_value = interpreter->visit(args[0]);

    if (var_value.type() != typeid(std::string))
        interpreter->error("1 argument in Split needs to be string");

    std::string value = boost::get<std::string>(var_value);
    std::string delimiter = " ";

    if (args.size() >= 2) {
        anything var_del = interpreter->visit(args[1]);

        if (var_del.type() == typeid(std::string))
            delimiter = boost::get<std::string>(var_del);
    }

    AST_Array* arr = new AST_Array(nullptr);

    size_t pos = 0;
    std::string token;
    while (1) {
        if (pos == std::string::npos)
            break;

        pos = value.find(delimiter);
        token = value.substr(0, pos);
        arr->items.push_back(token);
        value.erase(0, pos + delimiter.length());
    }

    return arr;
};
