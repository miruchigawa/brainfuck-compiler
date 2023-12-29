#pragma once
#include <fstream>
#include <string>

std::string LoadFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open " << filename << std::endl;
        return "";
    }
    
    std:: string code;
    std::string line;
    
    while (std::getline(file, line)) {
        code += line;
    }
    
    file.close();
    return code;
}