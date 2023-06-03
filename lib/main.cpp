/**
 * @file main.cpp
 * @brief Main entry point for the Generating program.
 * This program generates C/C++ code from text input files in respect of the passed parameters.
 * This file mages all these parameters and helps the user to understand how all of this works.
 */

#include "CTextToCPP.h"
#include "ProjectPathFinder.h"
#include <iostream>
#include <unistd.h>
#include <getopt.h>

// Color escape sequences
const std::string RESET_COLOR = "\033[0m";           /**< Reset color escape sequence */
const std::string GREEN_COLOR = "\033[32m";          /**< Green color escape sequence */
const std::string RED_COLOR = "\033[31m";            /**< Red color escape sequence */
const std::string CYAN_COLOR = "\033[36m";           /**< Cyan color escape sequence */
const std::string BLACK_COLOR = "\033[30m";          /**< Black color escape sequence */
const std::string BLUE_COLOR = "\033[38;5;19m";      /**< Blue color escape sequence */
const std::string STRONG_GREEN_COLOR = "\033[1;32m"; /**< Strong green color escape sequence */

// Project infomations
const std::string PROJECT_NAME = "GenTxtSrcCode";
ProjectPathFinder pathFinder("GenTxtSrcCode");
const std::string PROJECT_PATH = pathFinder.GetProjectFolderPath();

/**
 * @brief Print program arguments beautifully.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 */
void printArguments(const std::string &outputDir, const std::string &headerDir, const std::string &sourceDir, const std::string &outputType, const std::string &outputFilename, bool namespaceName, int signPerLine)
{
    std::cout << "Program arguments:\n";
    std::cout << "Output Directory: " << CYAN_COLOR << outputDir << RESET_COLOR << std::endl;
    std::cout << "Header Directory: " << CYAN_COLOR << headerDir << RESET_COLOR << std::endl;
    std::cout << "Source Directory: " << CYAN_COLOR << sourceDir << RESET_COLOR << std::endl;
    std::cout << "Output Type: " << CYAN_COLOR << outputType << RESET_COLOR << std::endl;
    std::cout << "Output Filename: " << CYAN_COLOR << outputFilename << RESET_COLOR << std::endl;
    std::cout << "Namespace Name: " << CYAN_COLOR << (namespaceName ? "Yes" : "No") << RESET_COLOR << std::endl;
    std::cout << "Sign Per Line: " << CYAN_COLOR << signPerLine << RESET_COLOR << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Main function.
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 * @return 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    std::string outputDir = PROJECT_PATH + "output\\"; /**< Output directory */
    std::string headerDir = outputDir + "include\\";   /**< Header file directory */
    std::string sourceDir = outputDir + "lib\\";       /**< Source file directory */
    std::string outputType = "CPP";                    /**< Output file type (C or CPP) */
    std::string outputFilename = "main";               /**< Output filename (without extension) */
    bool namespaceName;                                /**< Namespace yes or no (only for CPP) */
    int signPerLine = -1;                              /**< Number of characters per line */

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

            std::cout << "Usage: program_name [options] input-file1 input-file2 ...\n\n";
            std::cout << "-O, --output-dir <dir>    " << BLUE_COLOR << "Output directory" << RESET_COLOR << "\n";
            std::cout << "-H, --headerdir <dir>     " << BLUE_COLOR << "Header file directory" << RESET_COLOR << "\n";
            std::cout << "-S, --sourcedir <dir>     " << BLUE_COLOR << "Source file directory" << RESET_COLOR << "\n";
            std::cout << "-t, --output-type <type>  " << BLUE_COLOR << "Output file type (C or CPP)" << RESET_COLOR << "\n";
            std::cout << "-f, --output-filename <name>  " << BLUE_COLOR << "Output filename (without extension)" << RESET_COLOR << "\n";
            std::cout << "-n, --namespace <name>    " << BLUE_COLOR << "Namespace yes/no" << RESET_COLOR << "\n";
            std::cout << "-l, --signperline <number>  " << BLUE_COLOR << "Number of characters per line" << RESET_COLOR << "\n";
            std::cout << "-h, --help                " << BLUE_COLOR << "Print help message" << RESET_COLOR << "\n";

            std::cout << GREEN_COLOR << "\n\n################################################################################\n";
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

    printArguments(outputDir, headerDir, sourceDir, outputType, outputFilename, namespaceName, signPerLine);

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
