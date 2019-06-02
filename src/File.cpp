#include "File.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string ReadFile(const std::string &filePath)
{
    std::ifstream file;
    std::string line;

    std::stringstream content; 

    file.open(filePath);

    while (file)
    {
        getline(file, line);

        content << line << "\n";
    }

    file.close();

    return content.str();
}
