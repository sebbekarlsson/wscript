#include "includes/Lexer.hpp"
#include <sstream>
#include <iostream>
#include <map>


extern std::map<std::string, TokenType> RESERVED_KEYWORDS;

Lexer::Lexer(std::string text) {
    this->text = text;
    this->pos = 0;
    this->line = 0;
    this->current_char = this->text.at(this->pos);
    this->latest_token = new Token(TokenType::Empty, "");
};

Token* Lexer::get_next_token() {
    this->latest_token = this->_get_next_token();

    return this->latest_token;
};

/**
 * Collects the next token in the text
 *
 * @return Token*
 */
Token* Lexer::_get_next_token() {
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
            return new Token(TokenType::Newline, s);
        }

        if (this->current_char == '\'') {
            this->advance();
            this->skip_comment();
            continue;
        }

        if (this->current_char == '"')
            return this->str();

        if (isdigit(this->current_char))
            return this->number();

        if (isalpha(this->current_char))
            return this->_id();

        if (this->current_char == '<' && this->peek() == '>') {
            this->advance();
            this->advance();
            return new Token(TokenType::Noequals, s);
        }

        if (this->current_char == '>' && this->peek() == '=') {
            this->advance();
            this->advance();
            return new Token(TokenType::Larger_or_equals, s);
        }

        if (this->current_char == '<' && this->peek() == '=') {
            this->advance();
            this->advance();
            return new Token(TokenType::Less_or_equals, s);
        }
        
        if (this->current_char == '=' && this->peek() == '=') {
            this->advance();
            this->advance();
            return new Token(TokenType::Equals, "=");
        }

        if (this->current_char == '=') {
            this->advance();
            return new Token(TokenType::Assign, "=");
        }

        if (this->current_char == '>') {
            this->advance();
            return new Token(TokenType::Larger_than, s);
        }

        if (this->current_char == '<') {
            this->advance();
            return new Token(TokenType::Less_than, s);
        }

        if (this->current_char == ',') {
            this->advance();
            return new Token(TokenType::Comma, s);
        };

        if (this->current_char == ';') {
            this->advance();
            return new Token(TokenType::Semi, s);
        }

        if (this->current_char == '.') {
            this->advance();
            return new Token(TokenType::Dot, s);
        }

        if (this->current_char == '+') {
            this->advance();
            return new Token(TokenType::Plus, s);
        }

        if (this->current_char == '-') {
            this->advance();
            return new Token(TokenType::Minus, s);
        }

        if (this->current_char == '*') {
            this->advance();
            return new Token(TokenType::Multiply, s);
        }

        if (this->current_char == '/') {
            this->advance();
            return new Token(TokenType::Divide, s);
        }

        if (this->current_char == '(') {
            this->advance();
            return new Token(TokenType::Lparen, "(");
        }

        if (this->current_char == ')') {
            this->advance();
            return new Token(TokenType::Rparen, ")");
        }

        if (this->current_char == ':') {
            this->advance();
            return new Token(TokenType::Colon, s);
        }

        this->error("Unexpected: `" + s + "`");
    }

    return new Token(TokenType::Eof, "");
};

/**
 * Append single numbers into complete integers or floats
 *
 * @return Token*
 */
Token* Lexer::number() {
    Token* token;

    std::string result = "";

    while (this->current_char != '\0' && isdigit(this->current_char)) {
        result += this->current_char;
        this->advance();
    }
    
    if (this->current_char == '.') {
        result += this->current_char;
        this->advance();

        while (this->current_char != '\0' && isdigit(this->current_char)) {
            result += this->current_char;
            this->advance();
        }

        token = new Token(TokenType::Float, result);
    } else {
        token = new Token(TokenType::Integer, result);
    }

    return token;
};

Token* Lexer::str() {
    std::string result = "";
    
    this->advance();

    while (
        this->current_char != '\0' &&
        this->current_char != '\n' &&
        this->current_char != '"'
    ) {
        result += this->current_char;
        this->advance();
    }

    this->advance();

    return new Token(TokenType::String, result);
};

char Lexer::peek() {
    int peek_pos = this->pos + 1;

    if (peek_pos > (int)this->text.length()) {
        return '\0';
    }

    return this->text.at(peek_pos);
};

char Lexer::peek_next(int start) {
    int peek_pos = start;
    char c = '\0';

    while (peek_pos < (int)this->text.length()) {
        c = this->text.at(peek_pos);

        if (c == '\0' || c == ' ' || c == '\n') {
            peek_pos++;
            continue;
        } else {
            break;
        }
    }

    return c;
};

Token* Lexer::_id() {
    std::string result = "";

    while (this->current_char != '\0' && isalnum(this->current_char)) {
        result += this->current_char;
        this->advance();
    }

    if (RESERVED_KEYWORDS.find(result) != RESERVED_KEYWORDS.end()) {
        return new Token(RESERVED_KEYWORDS[result], result);
    } else if (this->latest_token->type != TokenType::Function_definition && this->peek_next(this->pos) == '(' && this->peek_next(this->pos) != '=') {
        return new Token(TokenType::Function_call, result);
    } else {
        return new Token(TokenType::Id, result);
    }

    return nullptr;
};

/**
 * Tells the lexer to go to the next character.
 */
void Lexer::advance() {
    this->pos += 1;

    if (this->current_char == '\n')
        this->line++;

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

void Lexer::error(std::string message) {
    throw std::runtime_error("[error][Lexer]:(line=" + std::to_string(this->line) + ",pos=" + std::to_string(this->pos) + ") " + message);
};
