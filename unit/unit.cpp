#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/includes/TOKEN_TYPES.hpp"
#include "../src/includes/Parser.hpp"
#include "../src/includes/Interpreter.hpp"
#include "../src/includes/Token.hpp"
#include "../src/includes/AST/AST_Num.hpp"
#include "../src/includes/AST/AST_BinOp.hpp"


extern std::string T_INTEGER;
extern std::string T_PLUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
    
Lexer* lexer = new Lexer(" ");
Parser* parser = new Parser(lexer);
Interpreter* interpreter = new Interpreter(parser);

TEST_CASE("BinOp", "[Testing BinOp]") {
    AST_Num* num0 = new AST_Num(new Token(T_INTEGER, "10"));
    AST_Num* num1 = new AST_Num(new Token(T_INTEGER, "20"));

    AST_BinOp* BinOp_PLUS = new AST_BinOp(num0, new Token(T_PLUS, "+"), num1);
    AST_BinOp* BinOp_MINUS = new AST_BinOp(num0, new Token(T_MINUS, "-"), num1);
    AST_BinOp* BinOp_MULTIPLY = new AST_BinOp(num0, new Token(T_MULTIPLY, "*"), num1);
    AST_BinOp* BinOp_DIVIDE = new AST_BinOp(num1, new Token(T_DIVIDE, "/"), num0);

    REQUIRE(interpreter->visit(BinOp_PLUS) == 30);
    REQUIRE(interpreter->visit(BinOp_MINUS) == -10);
    REQUIRE(interpreter->visit(BinOp_MULTIPLY) == 200);
    REQUIRE(interpreter->visit(BinOp_DIVIDE) == 2);
};
