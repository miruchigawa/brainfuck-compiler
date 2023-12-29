#pragma once
#include <string>
#include <vector>
#include <stack>

enum class TokenType {
    INC_PTR,
    DEC_PTR,
    INC_VAL,
    DEC_VAL,
    OUTPUT,
    INPUT,
    S_LOOP,
    E_LOOP,
    END
};

struct Token {
    TokenType type;
    int count;
};

class Lexer {
public:
    Lexer(std::string &source);
    ~Lexer();
    Token getNextToken();
private:
    std::string code;
    size_t pos;
};