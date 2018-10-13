#include "../includes/AST/AST_UBoundCall.hpp"
#include "../includes/AST/AST_Integer.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


extern std::string T_INTEGER;

AST_UBoundCall::AST_UBoundCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_UBoundCall::~AST_UBoundCall() {};

AST* AST_UBoundCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        interpreter->error("UBound requires 1 argument");

    anything arr = interpreter->visit(this->args[0]);

    if (arr.type() == typeid(std::vector<boost::any>)) {
        std::vector<boost::any> x = boost::get<std::vector<boost::any>>(arr);
        return new AST_Integer(new Token(T_INTEGER, std::to_string(x.size())));
    }

    return nullptr;
};
