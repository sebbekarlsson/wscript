#include "../includes/AST/AST_Function_isEmpty.hpp"
#include "../includes/AST/AST_Empty.hpp"
#include "../includes/AST/AST_Integer.hpp"
#include "../includes/typedefs.hpp"
#include <iostream>


AST_Function_isEmpty::AST_Function_isEmpty(std::string name) : AST_BuiltinFunctionDefinition(name) {
    this->expected_args.push_back(TokenType::String);
}

AST_Function_isEmpty::~AST_Function_isEmpty() {
};

AST* AST_Function_isEmpty::call(std::vector<AST*> args, Interpreter* interpreter) {
    if (args.size() == 0)
        interpreter->error("isEmpty requires 1 argument");

    int _is_empty = 0;

    anything _value = interpreter->visit(args[0]);

    if (_value.type() == typeid(AST*))
        if (dynamic_cast<AST_Empty*>(boost::get<AST*>(_value)))
            _is_empty = 1;

    // TODO: return AST_Boolean
    return new AST_Integer(new Token(TokenType::Integer, std::to_string(_is_empty)));
};
