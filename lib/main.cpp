/**
    @file main.cpp
    @brief Main entry point for the Generating program.
    This program generates C/C++ code from text input files in respect of the passed parameters.
    This file mages all these parameters and helps the user to understand how all of this works.
*/

#include "CTextToCPP.h"
#include <iostream>
#include <unistd.h>
#include <getopt.h>

// Color escape sequences
const std::string RESET_COLOR = "\033[0m";         // Reset color escape sequence
const std::string GREEN_COLOR = "\033[32m";        // Green color escape sequence
const std::string RED_COLOR = "\033[31m";          // Red color escape sequence
const std::string CYAN_COLOR = "\033[36m";         // Cyan color escape sequence
const std::string BLACK_COLOR = "\033[30m";        // Black color escape sequence
const std::string STRONG_GREEN_COLOR = "\033[92m"; // Strong green color escape sequence

/**
    @brief Main function.

    @param argc Number of command-line arguments.

    @param argv Array of command-line arguments.

    @return 0 on success, 1 on failure.
*/
int main(int argc, char *argv[])
{
    std::string outputDir;      // Output directory
    std::string headerDir;      // Header file directory
    std::string sourceDir;      // Source file directory
    std::string outputType;     // Output file type (C or CPP)
    std::string outputFilename; // Output filename (without extension)
    std::string namespaceName;  // Namespace yes or no
    int signPerLine = -1;       // Number of characters per line

    struct option longOptions[] = {
        {"output-dir", required_argument, nullptr, 'O'},
        {"headerdir", required_argument, nullptr, 'H'},
        {"sourcedir", required_argument, nullptr, 'S'},
        {"output-type", required_argument, nullptr, 't'},
        {"output-filename", required_argument, nullptr, 'f'},
        {"namespace", required_argument, nullptr, 'n'},
        {"signperline", required_argument, nullptr, 'l'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}};

    int opt;
    while ((opt = getopt_long(argc, argv, "O:H:S:t:f:n:l:h", longOptions, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'O':
            outputDir = optarg;
            break;
        case 'H':
            headerDir = optarg;
            break;
        case 'S':
            sourceDir = optarg;
            break;
        case 't':
            outputType = optarg;
            break;
        case 'f':
            outputFilename = optarg;
            break;
        case 'n':
            namespaceName = optarg;
            break;
        case 'l':
            signPerLine = std::stoi(optarg);
            break;
        case 'h':
            std::cout << STRONG_GREEN_COLOR << " ______  ______  __   __  ______  __  __  ______  ______  ______  ______  ______  ______  _____   ______    \n";
            std::cout << "/\\  ___\\/\\  ___\\/\\ \"-.\\ \\/\\__  _\\/\\_\\_\\/\\__  _\\/\\  ___\\/\\  == \\\\/\\  ___\\/\\  ___\\/\\  __ \\\\/\\  __-./\\  ___\\   \n";
            std::cout << "\\ \\ \\__ \\ \\  __\\\\ \\ \\-.  \\/_/\\ \\/\\/_/\\_\\/\\ \\/\\ \\/\\___  \\ \\  __<\\ \\ \\___\\ \\ \\___\\ \\ \\/\\ \\ \\ \\/\\ \\ \\  __\\   \n";
            std::cout << " \\ \\_____\\ \\_____\\ \\_\\\\\"\\_\\ \\ \\_\\  /\\/_/\\_\\ \\ \\_\\ \\/____/\\ \\_\\ \\_\\ \\_____\\ \\_____\\ \\_____\\ \\____-\\ \\_____\\ \n";
            std::cout << "  \\/_____/\\/_____/\\/_/ \\/_/  \\/_/  \\/_/\\/_/  \\/_/  \\/_____/\\/_/ /_/\\/_____/\\/_____/\\/_____/\\/____/ \\/_____/ \n";
            std::cout << "                                                                                                           \n"
                      << RESET_COLOR << std::endl;

            std::cout
                << "Usage: program_name [options] input-file1 input-file2 ...\n\n";
            std::cout << "-O, --output-dir <dir>    Output directory\n";
            std::cout << "-H, --headerdir <dir>     Header file directory\n";
            std::cout << "-S, --sourcedir <dir>     Source file directory\n";
            std::cout << "-t, --output-type <type>  Output file type (C or CPP)\n";
            std::cout << "-f, --output-filename <name>  Output filename (without extension)\n";
            std::cout << "-n, --namespace <name>    Namespace yes/no\n";
            std::cout << "-l, --signperline <number>  Number of characters per line\n";
            std::cout << "-h, --help                Print help message\n";

            std::cout << STRONG_GREEN_COLOR << "\n\n################################################################################\n";
            std::cout << "#                                                                              #\n";
            std::cout << "#                            Authors and Contact                               #\n";
            std::cout << "#                                                                              #\n";
            std::cout << "#          Authors: Anna-Sophie Schneider, Julia Egger, Jonas Lehmann,         #\n";
            std::cout << "#                         Christian Kerhault, Jamie Fisher                     #\n";
            std::cout << "#                                                                              #\n";
            std::cout << "#          Contact: kerhault.chris-it22.@it.dhbw-ravensburg.de                 #\n";
            std::cout << "#                                                                              #\n";
            std::cout << "################################################################################\n";
            std::cout << RESET_COLOR << std::endl;
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
