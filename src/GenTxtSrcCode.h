/**
 * This program generates C/C++ code from text input files in respect of the passed parameters.
 * This file mages all these parameters and helps the user to understand how all of this works.
 *
 * @file main.cpp
 * @brief Main entry point for the Generating program.
 */

#ifndef GENTXTSRCCODE_H
#define GENTXTSRCCODE_H

#include <Logger.h>
#include <map>
#include <getopt.h>
#include <unordered_set>

#include <ProjectPathFinder.h>
#include <Parameter.h>

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
    std::string PROJECT_NAME = "GenTxtSrcCode";
    ProjectPathFinder pathFinder; // Added braces for initialization
    const std::string PROJECT_PATH = pathFinder.getProjectFolderPath(PROJECT_NAME);

    struct ParamStruct parameterInfo;
    struct VariableStruct variableInfo;
    bool checkArgs = true;

    // Check if the name is a reserved keyword
    static std::unordered_set<std::string> reservedKeywords;

    // Options
    const static int optionsAmount = 10;
    const struct option longOptions[optionsAmount] = {
        {"headerdir", required_argument, nullptr, 'H'},
        {"sourcedir", required_argument, nullptr, 'S'},
        {"outputtype", required_argument, nullptr, 't'},
        {"outputfilename", required_argument, nullptr, 'f'},
        {"namespace", required_argument, nullptr, 'n'},
        {"signperline", required_argument, nullptr, 'l'},
        {"check", no_argument, nullptr, 'C'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}};

    std::string toLowerCase(const std::string &str);
    std::string toUpperCase(const std::string &str);

    /**
     * Checks and edits a given file path.
     *
     * @param path The file path to check and edit.
     * @return The edited file path.
     */
    std::string checkPath(const std::string &path);

    /**
     * @brief Clears the console screen
     */
    void clearConsole();

    /**
     * @brief Prints the help text with usage instructions and contact information.
     */
    void printHelpText();

    /**
     * Determine the programming language from string.
     *
     * @param input The input string to check.
     * @return The detected programming language: "cpp" for C++, "c" for C
     */
    std::string checkLanguageType(const std::string &input);

    /**
     * Checks if the provided file name is valid.
     *
     * @param fileName The file name to be validated.
     * @return True if the file name is valid, false otherwise.
     */
    void isValidFileName(const std::string &fileName);

    /**
     * Checks if the provided namespace is valid.
     *
     * @param fileName The namespace Name to be validated.
     * @return True if the namespace Name is valid, false otherwise.
     */
    void isValidNamespace(const std::string &ns);

    std::string isValidVariableName(const std::string &name, const std::string &filename);

    /**
     * @brief Parses the command-line options and sets the corresponding member variables.
     */
    void parseOptions();
    void checkOptions(std::map<std::string, std::string> &options);
    void checkVariable(std::map<std::string, std::string> &varibale, const std::string &filename);
    void printExtraction(std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables);

    /**
     * @brief Generates the code based on the parsed command-line options and input files.
     */
    void codeGeneration();

public:
    /**
     * @brief Constructor for the GenTxtSrcCode class.
     * @param argc The number of command-line arguments.
     * @param argv The array of command-line arguments.
     */
    GenTxtSrcCode(int argc, char *argv[]);
};

#endif // GENTXTSRCCODE_H
