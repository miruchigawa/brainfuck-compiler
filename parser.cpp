#include "parser.hpp"

Parser::Parser(const std::vector<Token> tokens) : _tokens(tokens) {}
Parser::~Parser() {}

void Parser::compile() {
    std::vector<char> memory(30000, 0);
    size_t data_pointer = 0;
    size_t loopstack[1000],lsp=0;
    
    for (size_t i = 0; i < _tokens.size(); i++) {
        const Token &curr_token = _tokens[i];
        
        switch (curr_token.type) {
            case TokenType::INC_PTR: ++data_pointer; break;
            case TokenType::DEC_PTR: --data_pointer; break;
            case TokenType::INC_VAL: ++memory[data_pointer]; break;
            case TokenType::DEC_VAL: --memory[data_pointer]; break;
            case TokenType::OUTPUT: std::cout << memory[data_pointer]; break;
            case TokenType::INPUT: memory[data_pointer]=getchar(); break;
            case TokenType::S_LOOP:
                if (memory[data_pointer])
                    loopstack[lsp++]=i;
                else {
                    size_t loop_depth = 0;
                    while (i < _tokens.size()) {
                        if (_tokens[i].type == TokenType::S_LOOP) {
                            ++loop_depth;
                        }else if(_tokens[i].type == TokenType::E_LOOP) {
                            --loop_depth;
                            if (loop_depth==0)
                                break;
                        }
                        ++i;
                    }
                }
                break;
            case TokenType::E_LOOP:
                i=loopstack[--lsp]-1;
                break;
            case TokenType::SKIP:
                break;
            case TokenType::END:
                break;
        }
    }
}
