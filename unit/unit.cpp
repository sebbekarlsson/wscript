#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include "../src/includes/Scope.hpp"
#include "../src/includes/TOKEN_TYPES.hpp"
#include "../src/includes/Parser.hpp"
#include "../src/includes/Interpreter.hpp"
#include "../src/includes/Token.hpp"
#include "../src/includes/AST/AST_Integer.hpp"
#include "../src/includes/AST/AST_BinOp.hpp"
#include "../src/includes/AST/AST_NoOp.hpp"


Scope* global_scope = new Scope("global");

extern std::string T_INTEGER;
extern std::string T_FLOAT;
extern std::string T_PLUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_DECLARE;
extern std::string T_ID;
extern std::string T_NEWLINE;
    
Lexer* lexer = new Lexer(" ");
Parser* parser = new Parser(lexer);
Interpreter* interpreter = new Interpreter(parser);

TEST_CASE("Lexer", "[Testing Lexer]") {
    Lexer* lex = new Lexer(
        std::string("Dim x\n") +
        std::string("x = 2 + 2 + 5.45")
    );

    REQUIRE(lex->get_next_token()->type == T_DECLARE);
    REQUIRE(lex->get_next_token()->type == T_ID);
    REQUIRE(lex->get_next_token()->type == T_NEWLINE);
    REQUIRE(lex->get_next_token()->type == T_ID);
    REQUIRE(lex->get_next_token()->type == T_ASSIGN);
    REQUIRE(lex->get_next_token()->type == T_INTEGER);
    REQUIRE(lex->get_next_token()->type == T_PLUS);
    REQUIRE(lex->get_next_token()->type == T_INTEGER);
    REQUIRE(lex->get_next_token()->type == T_PLUS);
    REQUIRE(lex->get_next_token()->type == T_FLOAT);
};

TEST_CASE("AST_BinOp", "[Testing AST_BinOp]") {
    AST_Integer* num0 = new AST_Integer(new Token(T_INTEGER, "10"));
    AST_Integer* num1 = new AST_Integer(new Token(T_INTEGER, "20"));

    AST_BinOp* BinOp_PLUS = new AST_BinOp(num0, new Token(T_PLUS, "+"), num1);
    AST_BinOp* BinOp_MINUS = new AST_BinOp(num0, new Token(T_MINUS, "-"), num1);
    AST_BinOp* BinOp_MULTIPLY = new AST_BinOp(num0, new Token(T_MULTIPLY, "*"), num1);
    AST_BinOp* BinOp_DIVIDE = new AST_BinOp(num1, new Token(T_DIVIDE, "/"), num0);

    REQUIRE(boost::get<int>(interpreter->visit(BinOp_PLUS)) == 30);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_MINUS)) == -10);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_MULTIPLY)) == 200);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_DIVIDE)) == 2);
};

TEST_CASE("AST_NoOp", "[Testing AST_NoOp]") {
    AST_NoOp* op = new AST_NoOp();

    REQUIRE(boost::get<int>(interpreter->visit(op)) == 0);
};
