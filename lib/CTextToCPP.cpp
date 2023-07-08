#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cstddef>
#include <Extractor.h>
#include <CTextToCPP.h>

CTextToCPP::CTextToCPP(const std::string &PROJECT_PATH, std::string &inputFilePath, struct ParamStruct &parameter)
{
    this->parameter = parameter;
    this->PROJECT_PATH = PROJECT_PATH;
    this->inputFilePath = inputFilePath;
}

void CTextToCPP::writeDeclaration()
{
    std::cout << "Hiii" << std::endl;
}

void CTextToCPP::writeImplementation()
{
    std::cout << "Hiii" << std::endl;
}

void CTextToCPP::addElement()
{
    std::cout << "Hiii" << std::endl;
}

void CTextToCPP::sort()
{
    std::cout << "Hiii" << std::endl;
}

void CTextToCPP::clear()
{
    std::cout << "Hiii" << std::endl;
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