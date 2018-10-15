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

Lexer* lexer = new Lexer(" ");
Parser* parser = new Parser(lexer);
Interpreter* interpreter = new Interpreter(parser);

TEST_CASE("Lexer", "[Testing Lexer]") {
    Lexer* lex = new Lexer(
        std::string("Dim x\n") +
        std::string("x = 2 + 2 + 5.45\n") +
        std::string("Dim a\na = Empty")
    );

    REQUIRE(lex->get_next_token()->type == TokenType::Declare);
    REQUIRE(lex->get_next_token()->type == TokenType::Id);
    REQUIRE(lex->get_next_token()->type == TokenType::Newline);
    REQUIRE(lex->get_next_token()->type == TokenType::Id);
    REQUIRE(lex->get_next_token()->type == TokenType::Assign);
    REQUIRE(lex->get_next_token()->type == TokenType::Integer);
    REQUIRE(lex->get_next_token()->type == TokenType::Plus);
    REQUIRE(lex->get_next_token()->type == TokenType::Integer);
    REQUIRE(lex->get_next_token()->type == TokenType::Plus);
    REQUIRE(lex->get_next_token()->type == TokenType::Float);
    REQUIRE(lex->get_next_token()->type == TokenType::Newline);
    REQUIRE(lex->get_next_token()->type == TokenType::Declare);
    REQUIRE(lex->get_next_token()->type == TokenType::Id);
    REQUIRE(lex->get_next_token()->type == TokenType::Newline);
    REQUIRE(lex->get_next_token()->type == TokenType::Id);
    REQUIRE(lex->get_next_token()->type == TokenType::Assign);
    REQUIRE(lex->get_next_token()->type == TokenType::Empty);
};

TEST_CASE("AST_BinOp", "[Testing AST_BinOp]") {
    AST_Integer* num0 = new AST_Integer(new Token(TokenType::Integer, "10"));
    AST_Integer* num1 = new AST_Integer(new Token(TokenType::Integer, "20"));

    AST_BinOp* BinOp_PLUS = new AST_BinOp(num0, new Token(TokenType::Plus, "+"), num1);
    AST_BinOp* BinOp_MINUS = new AST_BinOp(num0, new Token(TokenType::Minus, "-"), num1);
    AST_BinOp* BinOp_MULTIPLY = new AST_BinOp(num0, new Token(TokenType::Multiply, "*"), num1);
    AST_BinOp* BinOp_DIVIDE = new AST_BinOp(num1, new Token(TokenType::Divide, "/"), num0);

    REQUIRE(boost::get<int>(interpreter->visit(BinOp_PLUS)) == 30);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_MINUS)) == -10);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_MULTIPLY)) == 200);
    REQUIRE(boost::get<int>(interpreter->visit(BinOp_DIVIDE)) == 2);
};

TEST_CASE("AST_NoOp", "[Testing AST_NoOp]") {
    AST_NoOp* op = new AST_NoOp();

    REQUIRE(boost::get<int>(interpreter->visit(op)) == 0);
};
