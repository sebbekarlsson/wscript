#include "includes/Lexer.hpp"
#include <sstream>
#include <iostream>
#include <map>


extern std::string T_INTEGER;
extern std::string T_PLUS;
extern std::string T_MINUS;
extern std::string T_MULTIPLY;
extern std::string T_DIVIDE;
extern std::string T_EOF;
extern std::string T_LPAREN;
extern std::string T_RPAREN;
extern std::map<std::string, std::string> RESERVED_TOKENS;

Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->current_char = this->text.at(this->pos);
};

/**
 * Collects the next token in the text
 *
 * @return Token*
 */
Token* Lexer::get_next_token() {
    while (this->current_char != '\0' && (int)this->current_char != 10) {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }

        std::stringstream ss;
        std::string s;
        ss << this->current_char;
        ss >> s;

        if (isdigit(this->current_char))
            return new Token(T_INTEGER, std::to_string(this->integer()));

        if (isalpha(this->current_char))
            return this->_id();

        if (this->current_char == '+') {
            this->advance();
            return new Token(T_PLUS, s);
        }

        if (this->current_char == '-') {
            this->advance();
            return new Token(T_MINUS, s);
        }

        if (this->current_char == '*') {
            this->advance();
            return new Token(T_MULTIPLY, s);
        }

        if (this->current_char == '/') {
            this->advance();
            return new Token(T_DIVIDE, s);
        }

        if (this->current_char == '(') {
            this->advance();
            return new Token(T_LPAREN, "(");
        }

        if (this->current_char == ')') {
            this->advance();
            return new Token(T_RPAREN, ")");
        }

        throw std::runtime_error("Unexpected: `" + s + "`");
    }

    return new Token(T_EOF, "");
};

/**
 * Append single numbers into complete integers
 *
 * @return int
 */
int Lexer::integer() {
    std::string result = "";

    while (this->current_char != '\0' && isdigit(this->current_char)) {
        result += this->current_char;
        this->advance();
    }

    return std::stoi(result);
};

char Lexer::peek() {
    int peek_pos = this->pos + 1;

    if (peek_pos > (int)this->text.length()) {
        return '\0';
    }

    return this->text.at(peek_pos);
};

Token* Lexer::_id() {
    std::string result = "";

    Token* token;

    while (this->current_char != '\0' && isalnum(this->current_char)) {
        result += this->current_char;
        this->advance();
    }

    token = new Token(RESERVED_TOKENS[result], RESERVED_TOKENS[result]);

    return token;
};

/**
 * Tells the lexer to go to the next character.
 */
void Lexer::advance() {
    this->pos += 1;

    if (this->pos > (int)this->text.length() - 1) {
        this->current_char = '\0';
    } else {
        this->current_char = this->text.at(this->pos);
    }
};

/**
 * Tells the lexer to go to the next character until the
 * current_char is not whitespace.
 */
void Lexer::skip_whitespace() {
    while (this->current_char == ' ')
        this->advance();
};
