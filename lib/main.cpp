#include "CTextToCPP.h"
#include <iostream>
#include <unistd.h>
#include <getopt.h>

// Color escape sequences
const std::string RESET_COLOR = "\033[0m";
const std::string GREEN_COLOR = "\033[32m";
const std::string RED_COLOR = "\033[31m";

int main(int argc, char *argv[])
{
    std::string outputDir;
    std::string outputType;

    struct option longOptions[] = {
        {"output-dir", required_argument, nullptr, 'o'},
        {"output-type", required_argument, nullptr, 't'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}};

    int opt;
    while ((opt = getopt_long(argc, argv, "o:t:h", longOptions, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'o':
            outputDir = optarg;
            break;
        case 't':
            outputType = optarg;
            break;
        case 'h':
            std::cout << "Usage: program_name [options] input-file1 input-file2 ...\n";
            std::cout << "-o, --output-dir <dir>    Output directory\n";
            std::cout << "-t, --output-type <type>  Output file type (C or CPP)\n";
            std::cout << "-h, --help                Print help message\n";
            std::cout << "Authors: Anna-Sophie Schneider, Julia Egger, Jonas Lehmann, Christian Kerhault, Jamie Fisher\n";
            std::cout << "Contact: kerhault.chris-it22.@it.dhbw-ravensburg.de\n";
            return 0;
        case '?':
            std::cout << "Usage: program_name [options] input-file1 input-file2 ...\n";
            return 1;
        }
    }

    if (optind < argc)
    {
        try
        {
            CTextToCPP codeGenerator;
            for (int i = optind; i < argc; ++i)
            {
                std::string inputFileName = argv[i];
                codeGenerator.generateCode(inputFileName, outputDir, outputType);
                std::cout << GREEN_COLOR << "Code generation successful for file: " << inputFileName << RESET_COLOR << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << RED_COLOR << "Code generation failed: " << e.what() << RESET_COLOR << std::endl;
        }
    }
    else
    {
        std::cout << "Usage: program_name [options] input-file1 input-file2 ...\n";
    }

    return 0;
}
