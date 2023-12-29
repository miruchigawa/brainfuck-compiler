#include "lexer.hpp"
#include "parser.hpp"
#include "util.hpp"

int main(int argc, char** argv) {
    if (argc != 2){
        std::cerr << "Usage: " << argv[0] << " <filename.bf>" << std::endl;
        return 1;
    }
    
    std::string arg = argv[1];

    if (arg == "version") {
        std::cout << "Version 1.0 Github release." << std::endl;
    } else if (arg == "copyright") {
        std::cout << "©Copyright 2023 Miruchigawa | Compiler made by Miruchigawa https://github.com/miruchigawa" << std::endl;
    } else {
        std::string filename = argv[1];
        std::string code = LoadFile(filename);
        if (code.empty()) {
            return 1;
        }

        Lexer lexer(code);
        std::vector<Token> tokens;

        Token currentToken;
        while ((currentToken = lexer.getNextToken()).type != TokenType::END) {
            tokens.push_back(currentToken);
        }

        Parser parser(tokens);
        parser.compile();
    }

    return 0;
}
