/**
 * This program generates C/C++ code from text input files in respect of the passed parameters.
 * This file mages all these parameters and helps the user to understand how all of this works.
 *
 * @file main.cpp
 * @brief Main entry point for the Generating program.
 */

#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <regex>
#include <filesystem>

#include <cstdio>

#include <CTextToCPP.h>
#include <ProjectPathFinder.h>
#include <ConsoleColors.h>

/**
 * @class GenTxtSrcCode
 * @brief Handles the generation of C/C++ code based on user input parameters.
 */
class GenTxtSrcCode
{
private:
    int argc;
    char **argv;

    // Project infomations
    const std::string PROJECT_NAME = "GenTxtSrcCode";
    ProjectPathFinder pathFinder{"GenTxtSrcCode"}; // Added braces for initialization
    const std::string PROJECT_PATH = pathFinder.GetProjectFolderPath();

    // Standard directories
    std::string outputDir = PROJECT_PATH + "output\\"; /**< Output directory */
    std::string headerDir = outputDir + "include\\";   /**< Header file directory */
    std::string sourceDir = outputDir + "lib\\";       /**< Source file directory */
    std::string outputType = "cpp";                    /**< Output file type (C or CPP) */
    std::string outputFilename = "main";               /**< Output filename (without extension) */
    std::string namespaceName = "";                    /**< Namespace yes or no (only for CPP) */
    bool checkArgs = true;
    int signPerLine = 60; /**< Number of characters per line */

    // Options
    const static int options_amount = 10;
    const struct option longOptions[options_amount] = {
        {"output-dir", required_argument, nullptr, 'O'},
        {"headerdir", required_argument, nullptr, 'H'},
        {"sourcedir", required_argument, nullptr, 'S'},
        {"output-type", required_argument, nullptr, 't'},
        {"output-filename", required_argument, nullptr, 'f'},
        {"namespace", required_argument, nullptr, 'n'},
        {"signperline", required_argument, nullptr, 'l'},
        {"check", no_argument, nullptr, 'C'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}};

    /**
     * Checks and edits a given file path.
     *
     * @param path The file path to check and edit.
     * @return The edited file path.
     */
    std::string checkPath(const std::string &path)
    {
        std::filesystem::path fsPath(path);

        // Special cases: "." and "directiry" are considered relative paths
        if (fsPath == "." || fsPath == "directiry")
        {
            fsPath = std::filesystem::current_path();
        }
        else if (!fsPath.is_absolute())
        {
            fsPath = std::filesystem::absolute(fsPath);
        }

        std::string sanitizedPath = fsPath.string();

        // Replace forward slashes and single backslashes with double backslashes
        size_t found = sanitizedPath.find_first_of("/\\");
        while (found != std::string::npos)
        {
            sanitizedPath.replace(found, 1, "\\\\");
            found = sanitizedPath.find_first_of("/\\", found + 2);
        }

        return sanitizedPath;
    }

    /**
     * @brief Clears the console screen
     */
    void clearConsole()
    {
        std::cout << "\033[2J\033[1;1H";
    }

    /**
     * @brief Prints the program arguments.
     */
    void printArguments()
    {
        std::cout << "Program arguments:\n";
        std::cout << "Output Directory: " << CYAN_COLOR << outputDir << RESET_COLOR << std::endl;
        std::cout << "Header Directory: " << CYAN_COLOR << headerDir << RESET_COLOR << std::endl;
        std::cout << "Source Directory: " << CYAN_COLOR << sourceDir << RESET_COLOR << std::endl;
        std::cout << "Output Type: " << CYAN_COLOR << outputType << RESET_COLOR << std::endl;
        std::cout << "Output Filename: " << CYAN_COLOR << outputFilename << RESET_COLOR << std::endl;
        std::cout << "Namespace Name: " << CYAN_COLOR << (namespaceName) << RESET_COLOR << std::endl;
        std::cout << "Sign Per Line: " << CYAN_COLOR << signPerLine << RESET_COLOR << std::endl;
        std::cout << std::endl;
    }

    /**
     * @brief Prints the help text with usage instructions and contact information.
     */
    void printHelpText()
    {
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
        std::cout << "-n, --namespace <name>        " << BLUE_COLOR << "Flag to use namespaces" << RESET_COLOR << "\n";
        std::cout << "-l, --signperline <number>    " << BLUE_COLOR << "Number of characters per line" << RESET_COLOR << "\n";
        std::cout << "-C, --check                   " << BLUE_COLOR << "Flag to just create without checking the paths" << RESET_COLOR << "\n";
        std::cout << "-h, --help                    " << BLUE_COLOR << "Print help message" << RESET_COLOR << "\n";

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
    }

    /**
     * Determine the programming language from string.
     *
     * @param input The input string to check.
     * @return The detected programming language: "cpp" for C++, "c" for C
     */
    std::string checkLanguageType(const std::string &input)
    {
        if (input == "cpp" || input == "c++" || input == "g++")
        {
            return "cpp";
        }
        else if (input == "c")
        {
            return "c";
        }

        std::cout << RED_COLOR << "Cannot deterimine: " << BLUE_COLOR << "'" << input << "'" << RED_COLOR << " as a Language." << std::endl;
        std::cout << "We have " << CYAN_COLOR << "c " << RED_COLOR << "or " << CYAN_COLOR << "cpp " << RED_COLOR << "as option" << RESET_COLOR << std::endl;
        exit(1);
    }

    /**
     * Checks if the provided file name is valid.
     *
     * @param fileName The file name to be validated.
     * @return True if the file name is valid, false otherwise.
     */
    void isValidFileName(const std::string &fileName)
    {
        // Regular expression pattern for valid file name
        std::regex pattern(R"([^\x00-\x1F\x7F\\/:*?"<>|]+)");

        if (std::regex_match(fileName, pattern) == false)
        {
            std::cout << BLUE_COLOR << fileName << RED_COLOR << " is not a valid fileName" << RESET_COLOR << std::endl;
            exit(1);
        }
    }

    void isValidNamespace(const std::string &ns)
    {
        // Regular expression pattern for valid C++ namespace
        std::regex pattern("^(::)?[a-zA-Z_][a-zA-Z0-9_]*(::[a-zA-Z_][a-zA-Z0-9_]*)*$");

        // Check if the string matches the pattern
        if (std::regex_match(ns, pattern) == false)
        {
            std::cout << BLUE_COLOR << ns << RED_COLOR << " is not a valid namespace!" << RESET_COLOR << std::endl;
            exit(1);
        }
    }

    /**
     * @brief Parses the command-line options and sets the corresponding member variables.
     */
    void parseOptions()
    {
        int opt;
        int option_index;
        while ((opt = getopt_long(argc, argv, "O:H:S:t:f:n:l:Ch", longOptions, &option_index)) != -1)
        {
            std::string optionName;
            if (option_index > options_amount - 1 || option_index < 0)
            {
                optionName = "-";
                optionName += static_cast<char>(optopt);
                std::cout << optionName << std::endl;
            }
            else
            {
                optionName = "--";
                optionName += longOptions[option_index].name;
            }
            switch (opt)
            {
            case 'O':
                outputDir = checkPath(optarg);
                // isValidPath(optionName, outputDir);
                break;
            case 'H':
                headerDir = checkPath(optarg);
                // isValidPath(optionName, headerDir);
                break;
            case 'S':
                sourceDir = checkPath(optarg);
                // isValidPath(optionName, sourceDir);
                break;
            case 't':
                outputType = checkLanguageType(optarg);
                break;
            case 'f':
                outputFilename = optarg;
                isValidFileName(outputFilename);
                break;
            case 'n':
                if (outputType == "cpp")
                {
                    namespaceName = optarg;
                    isValidNamespace(namespaceName);
                }
                break;
            case 'l':
                signPerLine = std::stoi(optarg);
                break;
            case 'C':
                checkArgs = false;
                break;
            case 'h':
                printHelpText();
                exit(0);
            case '?':
                if ((optopt == 'O' || optopt == 'H' || optopt == 'S' || optopt == 't' || optopt == 'f' || optopt == 'n' || optopt == 'l'))
                {
                    std::cout << ORANGE_COLOR << "OK ... option " << optionName << "' without argument"
                              << RESET_COLOR << std::endl;
                    exit(1);
                }
                else if (isprint(optopt))
                {
                    std::cerr << RED_COLOR << "ERR ... Unknown option: " << optionName << RESET_COLOR << std::endl;
                    exit(-1);
                }
                else
                {
                    std::cerr << RED_COLOR << "ERR ... Unknown option character \\x" << optionName << RESET_COLOR << std::endl;
                    exit(-1);
                }
            }
        }
    }

    /**
     * @brief Generates the code based on the parsed command-line options and input files.
     */
    void codeGeneration()
    {
        if (optind < argc)
        {
            try
            {
                // CTextToCPP codeGenerator;
                for (int i = optind; i < argc; ++i)
                {
                    std::string inputFileName = argv[i];
                    // codeGenerator.generateCode(inputFileName, outputDir, outputType);
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
            std::cout << RED_COLOR << "Usage: program_name [options] input-file1 input-file2 ..." << RESET_COLOR << std::endl;
        }
    }

public:
    /**
     * @brief Constructor for the GenTxtSrcCode class.
     * @param argc The number of command-line arguments.
     * @param argv The array of command-line arguments.
     */
    GenTxtSrcCode(int argc, char *argv[]) : argc(argc), argv(argv)
    {
        parseOptions();
        if (checkArgs == true)
        {
            printArguments();
            std::cout << GREEN_COLOR << "Press any key to continue..." << RESET_COLOR << std::endl;
            getchar(); // Wait for any key
        }
        codeGeneration();
    }
};

/**
 * @brief The main entry point for the program.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return The exit code of the program.
 */
int main(int argc, char *argv[])
{
    EnableConsoleColors();
    GenTxtSrcCode generator(argc, argv);
    return 0;
}