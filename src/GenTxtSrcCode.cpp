#include <filesystem>
#include <iostream>
#include <regex>
#include <fstream>
#include <cctype>
#include <sstream>

#include <ConsoleColors.h>
#include <CTextToCPP.h>
#include <Extractor.h>
#include <GenTxtSrcCode.h>

std::unordered_set<std::string> GenTxtSrcCode::reservedKeywords = {
    // Add any other reserved keywords here
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"};

std::string GenTxtSrcCode::toLowerCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

std::string GenTxtSrcCode::toUpperCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::toupper(c);
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

std::string GenTxtSrcCode::isValidVariableName(const std::string &name, const std::string &filename)
{
    std::string new_name = name;
    // Check if the string is empty
    if (new_name.empty())
    {
        new_name = filename;
    }

    // Check if the first character is a letter or an underscore
    if (!std::isalpha(new_name[0]) && new_name[0] != '_')
    {
        BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << new_name << RED_COLOR << " is not a valid variable Name!\nIt has to start with a letter" << RESET_COLOR << std::endl;
        exit(1);
    }

    // Check if the remaining characters are letters, digits, or underscores
    for (std::size_t i = 1; i < new_name.length(); ++i)
    {
        char c = new_name[i];
        if (!std::isalnum(c) && c != '_')
        {
            BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << new_name << RED_COLOR << " is not a valid variable Name!\nOnly letters, daigits and underscores are allowed" << RESET_COLOR << std::endl;
            exit(1);
        }
    }

    int index = 0;
    std::string temp_name = new_name;
    while (reservedKeywords.find(new_name) != reservedKeywords.end())
    {
        new_name = temp_name;
        std::ostringstream oss;
        oss << std::setfill('0');
        oss << std::setw(2) << index;
        std::string formattedIndex = oss.str();
        new_name = new_name + formattedIndex;
        index += 1;
    }

    reservedKeywords.insert(new_name);
    return new_name;
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
            parameterInfo.headerDir = checkPath(optarg);
            ;
            // isValidPath(optionName, headerDir);
            break;
        case 'S':
            parameterInfo.sourceDir = checkPath(optarg);
            // isValidPath(optionName, sourceDir);
            break;
        case 't':
            parameterInfo.outputType = checkLanguageType(optarg);
            break;
        case 'f':
            parameterInfo.outputFilename = optarg;
            isValidFileName(parameterInfo.outputFilename);
            break;
        case 'n':
            parameterInfo.namespaceName = optarg;
            isValidNamespace(parameterInfo.namespaceName);
            break;
        case 'l':
            parameterInfo.signPerLine = std::stoi(optarg);
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
    std::string optValue;
    // WHY CANT I FCKN IETERATE A STRUCT???!!!
    if (parameterInfo.headerDir.empty())
    {
        optValue = options["headerdir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }

        parameterInfo.headerDir = checkPath(optValue);
    }
    if (parameterInfo.sourceDir.empty())
    {
        optValue = options["sourcedir"];
        if (optValue.empty())
        {
            optValue = PROJECT_PATH;
        }
        parameterInfo.sourceDir = checkPath(optValue);
    }
    if (parameterInfo.outputType.empty())
    {
        optValue = options["outputtype"];
        if (optValue.empty())
        {
            optValue = "cpp";
        }

        parameterInfo.outputType = checkLanguageType(optValue);
    }
    if (parameterInfo.outputFilename.empty())
    {
        optValue = options["outputfilename"];
        if (optValue.empty())
        {
            optValue = "main";
        }
        isValidFileName(optValue);
        parameterInfo.outputFilename = optValue;
    }
    if (parameterInfo.namespaceName.empty())
    {
        optValue = options["namespace"];
        if (optValue.empty())
        {
            optValue = "";
        }
        isValidNamespace(optValue);
        parameterInfo.namespaceName = optValue;
    }
    if (parameterInfo.signPerLine == 0)
    {
        optValue = options["signperline"];

        if (optValue.empty())
        {
            optValue = "60";
        }
        parameterInfo.signPerLine = std::stoi(optValue);
    }

    if (parameterInfo.sortByVarname == 0)
    {
        optValue = options["sortbyvarname"];
        if (optValue.empty())
        {
            optValue = "false";
        }
        if (optValue == "true")
        {
            parameterInfo.sortByVarname = true;
        }
        else
        {
            parameterInfo.sortByVarname = false;
        }
    }
}

void GenTxtSrcCode::checkVariable(std::map<std::string, std::string> &varibale, const std::string &filename)
{
    std::string optValue;

    variableInfo.VariableLineNumber = std::stoi(varibale.at("VariableLineNumber"));
    optValue = varibale["addtextpos"];
    if (optValue == "true")
    {
        variableInfo.addtextpos = true;
    }
    else
    {
        variableInfo.addtextpos = false;
    }

    optValue = varibale["addtextsegment"];
    if (optValue == "true")
    {
        variableInfo.addtextsegment = true;
    }
    else
    {
        variableInfo.addtextsegment = false;
    }

    variableInfo.doxygen = varibale["doxygen"];

    variableInfo.name = isValidVariableName(varibale["varname"], filename);

    optValue = toUpperCase(varibale["nl"]);
    if (optValue.empty() || optValue == "UNIX")
    {
        variableInfo.nl = "\n";
    }
    else if (optValue == "DOS")
    {
        variableInfo.nl = "\r\n";
    }
    else if (optValue == "MAC")
    {
        variableInfo.nl = "\r";
    }
    else
    {
        BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << filename << RED_COLOR << " nl is not Correct has to be (DOS,MAC,UNIX)\nGiven nl: " << optValue << RESET_COLOR << std::endl;
        exit(1);
    }
    variableInfo.seq = toUpperCase(varibale["seq"]);
    if (!(variableInfo.seq == "ESC" || variableInfo.seq == "HEX" || variableInfo.seq == "OCT" || variableInfo.seq == "RAWHEX"))
    {
        BOOST_LOG_TRIVIAL(fatal) << BLUE_COLOR << filename << RED_COLOR << " seq is not Correct has to be (ESC,HEX,OCT,RAWHEX)\nGiven nl: " << variableInfo.seq << RESET_COLOR << std::endl;
        exit(1);
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
                std::string userInputFileName = argv[i];
                std::string inputFilePath = checkPath(PROJECT_PATH + "\\" + userInputFileName);
                std::filesystem::path filePath(inputFilePath);
                std::string inputFileName = filePath.stem().string();

                std::ifstream inputFile(inputFilePath);
                std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

                std::map<std::string, std::string> options;
                std::vector<std::map<std::string, std::string>> variables;

                extractOptionsAndVariables(inputString, options, variables);
                checkOptions(options);

                for (std::map<std::string, std::string> &variable : variables)
                {
                    checkVariable(variable, inputFileName);
                }

                if (checkArgs == true)
                {
                    std::cout << BLUE_COLOR << inputFileName << " " << RESET_COLOR;
                    printParamStruct(parameterInfo);
                    std::cout << GREEN_COLOR << "Press any key to continue..." << RESET_COLOR << std::endl;
                    getchar(); // Wait for any key
                }

                CTextToCPP textToCPP(PROJECT_PATH, inputFilePath, parameterInfo);
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