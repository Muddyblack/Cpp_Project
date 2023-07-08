#include <filesystem>
#include <iostream>
#include <regex>
#include <fstream>
#include <cctype>

#include <ConsoleColors.h>
#include <CTextToCPP.h>
#include <Extractor.h>
#include <GenTxtSrcCode.h>

std::string GenTxtSrcCode::toLowerCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

std::string GenTxtSrcCode::checkPath(const std::string &path)
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

void GenTxtSrcCode::clearConsole()
{
    std::cout << "\033[2J\033[1;1H";
}

void GenTxtSrcCode::printHelpText()
{
    std::cout << STRONG_GREEN_COLOR << " ______  ______  __   __  ______  __  __  ______  ______  ______  ______  ______  ______  _____   ______    \n";
    std::cout << "/\\  ___\\/\\  ___\\/\\ \"-.\\ \\/\\__  _\\/\\_\\_\\/\\__  _\\/\\  ___\\/\\  == \\\\/\\  ___\\/\\  ___\\/\\  __ \\\\/\\  __-./\\  ___\\   \n";
    std::cout << "\\ \\ \\__ \\ \\  __\\\\ \\ \\-.  \\/_/\\ \\/\\/_/\\_\\/\\ \\/\\ \\/\\___  \\ \\  __<\\ \\ \\___\\ \\ \\___\\ \\ \\/\\ \\ \\ \\/\\ \\ \\  __\\   \n";
    std::cout << " \\ \\_____\\ \\_____\\ \\_\\\\\"\\_\\ \\ \\_\\  /\\/_/\\_\\ \\ \\_\\ \\/____/\\ \\_\\ \\_\\ \\_____\\ \\_____\\ \\_____\\ \\____-\\ \\_____\\ \n";
    std::cout << "  \\/_____/\\/_____/\\/_/ \\/_/  \\/_/  \\/_/\\/_/  \\/_/  \\/_____/\\/_/ /_/\\/_____/\\/_____/\\/_____/\\/____/ \\/_____/ \n";
    std::cout << "                                                                                                           \n"
              << RESET_COLOR << std::endl;

    std::cout << "Usage: program_name [options] input-file1 input-file2 ...\n\n";

    std::cout << "-H, --headerdir <dir>     " << BLUE_COLOR << "Header file directory" << RESET_COLOR << "\n";
    std::cout << "-S, --sourcedir <dir>     " << BLUE_COLOR << "Source file directory" << RESET_COLOR << "\n";
    std::cout << "-t, --outputtype <type>  " << BLUE_COLOR << "Output file type (C or CPP)" << RESET_COLOR << "\n";
    std::cout << "-f, --outputfilename <name>  " << BLUE_COLOR << "Output filename (without extension)" << RESET_COLOR << "\n";
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

std::string GenTxtSrcCode::checkLanguageType(const std::string &input)
{
    const std::string input_lower = toLowerCase(input);
    if (input_lower == "cpp" || input_lower == "c++" || input_lower == "g++")
    {
        return "cpp";
    }
    else if (input_lower == "c")
    {
        return "c";
    }

    BOOST_LOG_TRIVIAL(fatal) << RED_COLOR << "Cannot deterimine: " << BLUE_COLOR << "'" << input << "'" << RED_COLOR << " as a Language."
                             << "\n"
                             << "We have " << CYAN_COLOR << "c " << RED_COLOR << "or " << CYAN_COLOR << "cpp " << RED_COLOR << "as option" << RESET_COLOR << std::endl;
    exit(1);
}

void GenTxtSrcCode::isValidFileName(const std::string &fileName)
{
    // Regular expression pattern for valid file name
    std::regex pattern(R"([^\x00-\x1F\x7F\\/:*?"<>|]+)");

    if (std::regex_match(fileName, pattern) == false)
    {
        BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << fileName << RED_COLOR << " is not a valid fileName" << RESET_COLOR << std::endl;
        exit(1);
    }
}

void GenTxtSrcCode::isValidNamespace(const std::string &ns)
{
    // Regular expression pattern for valid C++ namespace
    std::regex pattern("^(::)?[a-zA-Z_][a-zA-Z0-9_]*(::[a-zA-Z_][a-zA-Z0-9_]*)*$");

    // Check if the string matches the pattern
    if (std::regex_match(ns, pattern) == false)
    {
        BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << ns << RED_COLOR << " is not a valid namespace!" << RESET_COLOR << std::endl;
        exit(1);
    }
}

void GenTxtSrcCode::parseOptions()
{
    int opt;
    int optionIndex;

    BOOST_LOG_TRIVIAL(info) << "Checking for User-Input";
    while ((opt = getopt_long(argc, argv, "H:S:t:f:n:l:Ch", longOptions, &optionIndex)) != -1)
    {
        std::string optionName;
        if (optionIndex > optionsAmount - 1 || optionIndex < 0)
        {
            optionName = "-";
            optionName += static_cast<char>(optopt);
        }
        else
        {
            optionName = "--";
            optionName += longOptions[optionIndex].name;
        }
        switch (opt)
        {
        case 'H':
            parameter.headerDir = checkPath(optarg);
            ;
            // isValidPath(optionName, headerDir);
            break;
        case 'S':
            parameter.sourceDir = checkPath(optarg);
            // isValidPath(optionName, sourceDir);
            break;
        case 't':
            parameter.outputType = checkLanguageType(optarg);
            break;
        case 'f':
            parameter.outputFilename = optarg;
            isValidFileName(parameter.outputFilename);
            break;
        case 'n':
            if (parameter.outputType == "cpp")
            {
                parameter.namespaceName = optarg;
                isValidNamespace(parameter.namespaceName);
            }
            break;
        case 'l':
            parameter.signPerLine = std::stoi(optarg);
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
                BOOST_LOG_TRIVIAL(fatal) << ORANGE_COLOR << "OK ... option " << optionName << "' without argument"
                                         << RESET_COLOR << std::endl;
                exit(1);
            }
            else if (isprint(optopt))
            {
                BOOST_LOG_TRIVIAL(fatal) << RED_COLOR << "ERR ... Unknown option: " << optionName << RESET_COLOR << std::endl;
                exit(-1);
            }
            else
            {
                BOOST_LOG_TRIVIAL(fatal) << RED_COLOR << "ERR ... Unknown option character \\x" << optionName << RESET_COLOR << std::endl;
                exit(-1);
            }
        }
    }
}

void GenTxtSrcCode::checkOptions(std::map<std::string, std::string> &options)
{
    // WHY CANT I FCKN IETERATE A STRUCT???!!!
    if (parameter.headerDir.empty())
    {
        std::string optValue = options["headerdir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }

        parameter.headerDir = checkPath(optValue);
    }
    if (parameter.sourceDir.empty())
    {
        std::string optValue = options["sourcedir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }
        parameter.sourceDir = checkPath(optValue);
    }
    if (parameter.outputType.empty())
    {
        std::string optValue = options["outputtype"];
        if (optValue.empty())
        {
            optValue = "cpp";
        }

        parameter.outputType = checkLanguageType(optValue);
    }
    if (parameter.outputFilename.empty())
    {
        std::string optValue = options["outputfilename"];
        if (optValue.empty())
        {
            optValue = "main";
        }
        isValidFileName(optValue);
        parameter.outputFilename = optValue;
    }
    if (parameter.namespaceName.empty())
    {
        std::string optValue = options["namespace"];
        if (optValue.empty())
        {
            optValue = "";
        }
        isValidNamespace(optValue);
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
        if (optValue == "true")
        {
            parameter.sortByVarname = true;
        }
        else
        {
            parameter.sortByVarname = false;
        }
    }
}

void GenTxtSrcCode::printExtraction(std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables)
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

void GenTxtSrcCode::codeGeneration()
{
    if (optind < argc)
    {
        try
        {
            for (int i = optind; i < argc; ++i)
            {
                // This is where the magic happens
                std::string inputFileName = argv[i];
                std::string inputFilePath = PROJECT_PATH + "\\" + inputFileName;

                std::ifstream inputFile(inputFilePath);
                std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

                std::map<std::string, std::string> options;
                std::vector<std::map<std::string, std::string>> variables;

                extractOptionsAndVariables(inputString, options, variables);
                checkOptions(options);

                if (checkArgs == true)
                {
                    printParamStruct(parameter);
                    std::cout << GREEN_COLOR << "Press any key to continue..." << RESET_COLOR << std::endl;
                    getchar(); // Wait for any key
                }

                CTextToCPP textToCPP(PROJECT_PATH, inputFilePath, parameter);
                textToCPP.generateCode();

                BOOST_LOG_TRIVIAL(info) << GREEN_COLOR << "Code generation successful for file: " << inputFileName << RESET_COLOR << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            BOOST_LOG_TRIVIAL(error) << RED_COLOR << "Code generation failed: " << e.what() << RESET_COLOR << std::endl;
        }
    }
    else
    {
        BOOST_LOG_TRIVIAL(warning) << RED_COLOR << "Usage: program_name [options] input-file1 input-file2 ..." << RESET_COLOR << std::endl;
    }
}

GenTxtSrcCode::GenTxtSrcCode(int argc, char *argv[]) : argc(argc), argv(argv)
{
    setup_logging(PROJECT_PATH + "/GenTxtSrcCode.log");

    BOOST_LOG_TRIVIAL(info) << "Starting Programm";
    parseOptions();
    codeGeneration();
}

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