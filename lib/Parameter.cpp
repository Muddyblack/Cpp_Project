#include <Parameter.h>
#include <ConsoleColors.h>

void printParamStruct(const ParamStruct &paramStruct)
{
    std::cout << "Program arguments:\n";
    std::cout << "Header Directory: " << CYAN_COLOR << paramStruct.headerDir << RESET_COLOR << std::endl;
    std::cout << "Source Directory: " << CYAN_COLOR << paramStruct.sourceDir << RESET_COLOR << std::endl;
    std::cout << "Output Type: " << CYAN_COLOR << paramStruct.outputType << RESET_COLOR << std::endl;
    std::cout << "Output Filename: " << CYAN_COLOR << paramStruct.outputFilename << RESET_COLOR << std::endl;
    std::cout << "Namespace Name: " << CYAN_COLOR << (paramStruct.namespaceName) << RESET_COLOR << std::endl;
    std::cout << "Sign Per Line: " << CYAN_COLOR << paramStruct.signPerLine << RESET_COLOR << std::endl;
    std::cout << std::endl;
}