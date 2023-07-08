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

void CTextToCPP::checkOptions()
{
    // WHY CANT I FCKN IETERATE A STRUCT???!!!
    if (parameter.headerDir.empty())
    {
        std::string optValue = options["headerdir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }
        parameter.headerDir = optValue;
    }
    if (parameter.sourceDir.empty())
    {
        std::string optValue = options["sourcedir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }
        parameter.sourceDir = optValue;
    }
    if (parameter.outputType.empty())
    {
        std::string optValue = options["outputtype"];
        if (optValue.empty())
        {
            optValue = "cpp";
        }

        parameter.outputType = optValue;
    }
    if (parameter.outputFilename.empty())
    {
        std::string optValue = options["outputfilename"];
        if (optValue.empty())
        {
            optValue = "main";
        }
        parameter.outputFilename = optValue;
    }
    if (parameter.namespaceName.empty())
    {
        std::string optValue = options["namespace"];
        if (optValue.empty())
        {
            optValue = "";
        }
        parameter.namespaceName = optValue;
    }
    if (parameter.signPerLine == 0)
    {
        std::string optValue = options["signperline"];
        if (optValue.empty())
        {
            optValue = "60";
        }
        parameter.signPerLine = std::stoi(optValue);
    }

    if (parameter.sortByVarname == 0)
    {
        std::string optValue = options["sortbyvarname"];
        if (optValue.empty())
        {
            optValue = "false";
        }
        parameter.sortByVarname = std::stoi(optValue);
    }
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