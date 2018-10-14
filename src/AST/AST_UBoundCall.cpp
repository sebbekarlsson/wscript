#include "../includes/AST/AST_UBoundCall.hpp"
#include "../includes/AST/AST_Integer.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_UBoundCall::AST_UBoundCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_UBoundCall::~AST_UBoundCall() {};

AST* AST_UBoundCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        interpreter->error("UBound requires 1 argument");

    anything arr = interpreter->visit(this->args[0]);

    if (arr.type() == typeid(AST*)) {
        AST* ast = boost::get<AST*>(arr);

        if (dynamic_cast<AST_Array*>(ast)) {
            AST_Array* _arr = (AST_Array*)ast;

            return new AST_Integer(new Token(TokenType::Integer, std::to_string(_arr->items.size())));
        }
    } else if (arr.type() == typeid(std::string)) {
        return new AST_Integer(new Token(TokenType::Integer, std::to_string(boost::get<std::string>(arr).size())));
    }

    return nullptr;
};
