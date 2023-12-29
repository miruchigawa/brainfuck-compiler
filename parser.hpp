#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include "lexer.hpp"

class Parser {
public:
    Parser(const std::vector<Token> tokens);
    ~Parser();
    void compile();
private:
    std::vector<Token> _tokens;
};