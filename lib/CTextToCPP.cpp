#include <iostream>
#include <vector>
#include <fstream>
#include <map>

#include <Extractor.h>
#include <CTextToCPP.h>

CTextToCPP::CTextToCPP(const std::string &inputFilePath, const std::string &outputDir, const std::string &outputType)
{
    std::ifstream inputFile(inputFilePath);
    std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    std::map<std::string, std::string> options;
    std::vector<std::map<std::string, std::string>> variables;

    extractOptionsAndVariables(inputString, options, variables);

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

void CTextToCPP::generateCode(const std::string &inputFileName, const std::string &outputDir, const std::string &outputType)
{
    // Code generation implementation for the specified file goes here
    // For example: Open the file, read its content, and save it as header and source files
    // Save the files in the specified output directory
}

CTextToCPP::~CTextToCPP()
{
    // Destructor implementation (if needed)
}

/*
int main()
{
    CTextToCPP textToCPP("C:\\Users\\Muddyblack\\OneDrive - bwedu\\12 Studium\\01 DHBW\\2. Semester\\18 C und C++ Kurs\\GenTxtSrcCode\\.examples\\sample.txt", "dsad", "dasd");
    //CTextToCPP textToCPP("/home/muddyblack/Downloads/GenTxtSrcCode/.examples/sample.txt", "dsad", "dasd");

    return 0;
}*/