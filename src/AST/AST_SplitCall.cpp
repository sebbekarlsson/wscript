#include "../includes/AST/AST_SplitCall.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/AST/AST_NoOp.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>
#include <sstream>


AST_SplitCall::AST_SplitCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_SplitCall::~AST_SplitCall() {};

AST* AST_SplitCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        return new AST_NoOp();

    anything var_value = interpreter->visit(this->args[0]);

    if (var_value.type() != typeid(std::string))
        interpreter->error("1 argument in Split needs to be string");

    std::string value = boost::get<std::string>(var_value);
    std::string delimiter = " ";

    if (this->args.size() >= 2) {
        anything var_del = interpreter->visit(this->args[1]);

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
