#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <Extractor.h>
#include <CTextToCPP.h>
#include <Parameter.h>

CTextToCPP::CTextToCPP(std::string &inputFilePath, struct ParamStruct &parameter)
{
    std::ifstream inputFile(inputFilePath);
    std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    extractOptionsAndVariables(inputString, options, variables);
}

void CTextToCPP::printExtraction()
{
    std::cout << "Options:\n";
    for (const auto &option : options)
    {
        std::cout << option.first << ": " << option.second << '\n';
    }

    std::cout << "\nVariables:\n";
    for (const auto &variable : variables)
    {
        for (const auto &key : variable)
        {
            std::cout << key.first << ": " << key.second << '\n';
        }

        std::cout << "\n\n";
    }
}

void CTextToCPP::generateCode()
{
    // Code generation implementation for the specified file goes here
    // For example: Open the file, read its content, and save it as header and source files
    // Save the files in the specified output directory
}

CTextToCPP::~CTextToCPP()
{
    // Destructor implementation (if needed)
}