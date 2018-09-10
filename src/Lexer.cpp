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
extern std::string T_ASSIGN;
extern std::string T_DOT;
extern std::string T_SEMI;
extern std::string T_ID;
extern std::string T_COMMA;
extern std::string T_NEWLINE;
extern std::map<std::string, std::string> RESERVED_KEYWORDS;

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
    while (this->current_char != '\0') {
        if (this->current_char == ' ') {
            this->skip_whitespace();
            continue;
        }

        std::stringstream ss;
        std::string s;
        ss << this->current_char;
        ss >> s;

        if (this->current_char == '\n' || (int)this->current_char == 10) {
            this->advance();
            
            return new Token(T_NEWLINE, s);
        }

        if (this->current_char == '\'') {
            this->advance();
            this->skip_comment();
            continue;
        }

        if (isdigit(this->current_char))
            return new Token(T_INTEGER, std::to_string(this->integer()));

        if (isalpha(this->current_char))
            return this->_id();

        if (this->current_char == '=') {
            this->advance();

            return new Token(T_ASSIGN, "=");
        }

        if (this->current_char == ',') {
            this->advance();
            return new Token(T_COMMA, s);
        };

        if (this->current_char == ';') {
            this->advance();
            return new Token(T_SEMI, s);
        }

        if (this->current_char == '.') {
            this->advance();
            return new Token(T_DOT, s);
        }

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

    return new Token(T_EOF, T_EOF);
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

    if (RESERVED_KEYWORDS.find(result) != RESERVED_KEYWORDS.end()) {
        token = new Token(RESERVED_KEYWORDS[result], RESERVED_KEYWORDS[result]);
    } else {
        token = new Token(T_ID, result);
    }

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
    while (this->current_char == ' ' || (int)this->current_char == 10)
        this->advance();
};

void Lexer::skip_comment() {
    while (this->current_char != '\n')
        this->advance();
};
