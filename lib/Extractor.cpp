#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <boost/tokenizer.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <Logger.h>
#include <ConsoleColors.h>
#include <Extractor.h>

/**
 * @brief Saves a Json string in a dictionary
 * @param jsonString 
 * @return dictionary of key-value pairs
 */

std::map<std::string, std::string> parseJsonString(const std::string &jsonString)
{
    std::map<std::string, std::string> dictionary;
    boost::property_tree::ptree pt;

    // Loading the JSON string into the property tree
    std::istringstream jsonStream(jsonString);
    boost::property_tree::read_json(jsonStream, pt);

    // Iterates each key-value pair in the property tree and add it to the dictionary
    for (const auto &keyValue : pt)
    {
        const std::string &key = keyValue.first;
        const std::string &value = keyValue.second.get_value<std::string>();
        dictionary[key] = value;
    }

    return dictionary;
}

/**
 * @brief extracts all Options and Variables from the input File
 * @param inputFilePath Path of the File you want to read from
 * @param options different options that are fixed in the input File
 * @param variables different variables that are fixed in the input File
 */

void extractOptionsAndVariables(const std::string &inputFilePath, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables)
{
    boost::char_separator<char> newlineSeparator("\n");

    bool currentVariable = false;
    std::map<std::string, std::string> currentVarDic;
    std::string currentContent;
    bool work = false;
    bool started = false;

    // Differentiates between different @´s
    const std::string startString = "@start";
    const std::string endString = "@end";
    const std::string globalString = "@global";
    const std::string variableString = "@variable";
    const std::string endVariableString = "@endvariable";

    // Number of lines
    int lineNumber = 0;

    std::ifstream inputFile(inputFilePath);
    std::string inputString((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    char x = '@';

    // Check if @ even exists in the file
    if (inputString.find(x) == std::string::npos)
    {
        return;
    }

    std::istringstream iss(inputString);
    std::string line;

    // Read all lines of the file, one after another
    while (std::getline(iss, line))
    {
        lineNumber++;

        // If @start and everything before the first ' ' are the same and if the currentVariable is false
        if (startString == line.substr(0, line.find(' ')) && currentVariable == false)
        {
            work = true;
            started = true;
        }
        // Terminate when @end and everything before the first ' ' are the same
        else if (endString == line.substr(0, line.find(' ')) && currentVariable == false)
        {
            work = false;
            break;
        }
        // If the first if condition is true:
        else if (work)
        {
            // If @global and everything before the first ' ' are the same
            if (globalString == line.substr(0, line.find(' ')) && currentVariable == false)
            {
                std::string::size_type startPos = line.find("{");
                std::string::size_type endPos = line.find("}");
                if (startPos != std::string::npos)
                {
                    std::string variableString = line.substr(startPos, endPos - startPos + 1);

                    std::map<std::string, std::string> tempOptions = parseJsonString(variableString);
                    options.insert(tempOptions.begin(), tempOptions.end());
                }
            }
            // If @variable and everything before the first ' ' are the same
            else if (variableString == line.substr(0, line.find(' ')) && currentVariable == false)
            {
                currentVarDic.clear();

                std::string::size_type startPos = line.find("{");
                std::string::size_type endPos = line.find("}");
                if (startPos != std::string::npos)
                {
                    std::string variableString = line.substr(startPos, endPos - startPos + 1);

                    currentVarDic = parseJsonString(variableString);
                    currentVarDic.insert({"VariableLineNumber", std::to_string(lineNumber)});
                    currentVariable = true;
                }
            }
            // If @endvariable and everything before the first ' ' are the same
            else if (endVariableString == line.substr(0, line.find(' ')) && currentVariable == true)
            {
                currentVariable = false;
                currentVarDic["content"] = currentContent;
                variables.push_back(currentVarDic);
                currentContent.clear();
            }
            // If currentVariable  is still true, End of the Variable was reached
            else if (currentVariable)
            {
                currentContent += line;
                currentContent += "\n";
            }
        }
    }
    // In case first if condition was never met, no @start Tag
    if (started == false)
    {
        BOOST_LOG_TRIVIAL(fatal)
            << RED_COLOR << "This file has no @start-Tag: " << inputFilePath << RESET_COLOR << std::endl;
        exit(1);
    }
}
