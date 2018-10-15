#include "../includes/AST/AST_isEmptyCall.hpp"
#include "../includes/AST/AST_Empty.hpp"
#include "../includes/AST/AST_Integer.hpp"
#include "../includes/Token.hpp"
#include "../includes/Interpreter.hpp"
#include <iostream>


AST_isEmptyCall::AST_isEmptyCall(std::vector<AST*> args) : AST_FunctionCall(args) {};

AST_isEmptyCall::~AST_isEmptyCall() {};

AST* AST_isEmptyCall::call(Interpreter* interpreter) {
    if (this->args.size() == 0)
        interpreter->error("isEmpty requires 1 argument");

    int _is_empty = 0;

    anything _value = interpreter->visit(this->args[0]);

    if (_value.type() == typeid(AST*))
        if (dynamic_cast<AST_Empty*>(boost::get<AST*>(_value)))
            _is_empty = 1;

    // TODO: return AST_Boolean
    return new AST_Integer(new Token(TokenType::Integer, std::to_string(_is_empty)));
};
