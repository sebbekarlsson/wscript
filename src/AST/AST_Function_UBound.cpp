#include "../includes/AST/AST_Function_UBound.hpp"
#include "../includes/AST/AST_Array.hpp"
#include "../includes/typedefs.hpp"
#include <iostream>


AST_Function_UBound::AST_Function_UBound(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->expected_args.push_back(TokenType::Anything);
}

AST_Function_UBound::~AST_Function_UBound() {
};

AST* AST_Function_UBound::call(std::vector<AST*> args, Interpreter* interpreter) {
    if (args.size() == 0)
        interpreter->error("UBound requires 1 argument");

    anything arr = interpreter->visit(args[0]);

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
