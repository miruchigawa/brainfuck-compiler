#include "lexer.hpp"

Lexer::Lexer(std::string &source) : code(source), pos(0) {}
Lexer::~Lexer() {}

Token Lexer::getNextToken() {
    if (pos >= code.size()) {
        return { TokenType::END, 0};
    }
    
    char curr_char = code[pos++];
    
    switch (curr_char) {
        case '>': return {TokenType::INC_PTR, 1};
        case '<': return {TokenType::DEC_PTR, 1};
        case '+': return {TokenType::INC_VAL, 1};
        case '-': return {TokenType::DEC_VAL, 1};
        case '.': return {TokenType::OUTPUT, 1};
        case ',': return {TokenType::INPUT, 1};
        case '[': return {TokenType::S_LOOP, 0};
        case ']': return {TokenType::E_LOOP, 0};
        default: return Lexer::getNextToken();
    }
}