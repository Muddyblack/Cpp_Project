#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <boost/tokenizer.hpp>

#include <Extractor.h>
/**
 * Strips leading and trailing whitespace characters from a given string.
 *
 * @param str The input string to be stripped.
 * @return The input string with leading and trailing whitespace removed.
 */
std::string stripString(const std::string &str)
{
    if (str.empty())
    {
        return str;
    }

    std::string result = str;
    // Remove leading whitespace
    size_t startPos = result.find_first_not_of(" \t");
    if (startPos != std::string::npos)
    {
        result = result.substr(startPos);
    }

    // Remove trailing whitespace
    size_t endPos = result.find_last_not_of(" \t");
    if (endPos != std::string::npos)
    {
        result = result.substr(0, endPos + 1);
    }

    return result;
}

/**
 * Removes leading and trailing quotation marks from a given string.
 *
 * @param str The input string to remove quotation marks from.
 * @return The input string with leading and trailing quotation marks removed.
 */
std::string removeLeadTailQuotes(const std::string &str)
{
    if (str.empty())
    {
        return str;
    }

    std::string result = stripString(str);
    if (result[0] == '"')
    {
        // Remove the first character
        result = result.substr(1);
    }

    // Check if the last character is a double quote
    if (result[result.length() - 1] == '"')
    {
        // Remove the last character
        result = result.substr(0, result.length() - 1);
    }

    return stripString(result);
}

/**
 * Extracts options and variables from an input string and populates the provided maps and vector.
 *
 * @param inputString The input string containing options and variables.
 * @param options The map to store extracted options (key-value pairs).
 * @param variables The vector of maps to store extracted variables (key-value pairs).
 */
void extractOptionsAndVariables(const std::string &inputString, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables)
{
    typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
    boost::char_separator<char> newlineSeparator("\n");

    tokenizer lines(inputString, newlineSeparator);
    bool currentVariable = false;
    std::map<std::string, std::string> currentVarDic;
    std::string currentContent;
    bool work = false;

    const std::string startString = "@start";
    const std::string endString = "@end";
    const std::string globalString = "@global";
    const std::string variableString = "@variable";
    const std::string endVariableString = "@endvariable";

    for (const std::string &line : lines)
    {
        if (startString == line.substr(0, line.find(' ')) && currentVariable == false)
        {
            work = true;
        }
        else if (endString == line.substr(0, line.find(' ')) && currentVariable == false)
        {
            work = false;
            break;
        }
        else if (work)
        {
            if (globalString == line.substr(0, line.find(' ')) && currentVariable == false)
            {
                std::string::size_type startPos = line.find("{");
                std::string::size_type endPos = line.find("}");
                if (startPos != std::string::npos)
                {
                    std::string optionString = line.substr(startPos + 1, endPos - startPos - 1);
                    tokenizer tokenizer(optionString, boost::char_separator<char>(","));
                    for (const std::string &keys : tokenizer)
                    {
                        std::string::size_type colonPos = keys.find(":");
                        if (colonPos != std::string::npos)
                        {
                            std::string key = removeLeadTailQuotes(keys.substr(0, colonPos));
                            std::string value = removeLeadTailQuotes(keys.substr(colonPos + 1));
                            options[key] = value;
                        }
                    }
                }
            }
            else if (variableString == line.substr(0, line.find(' ')) && currentVariable == false)
            {
                currentVarDic.clear();

                std::string::size_type startPos = line.find("{");
                std::string::size_type endPos = line.find("}");
                if (startPos != std::string::npos)
                {
                    std::string variableString = line.substr(startPos + 1, endPos - startPos - 1);
                    tokenizer tokenizer(variableString, boost::char_separator<char>(","));
                    for (const std::string &keys : tokenizer)
                    {
                        std::string::size_type colonPos = keys.find(":");
                        if (colonPos != std::string::npos)
                        {
                            std::string key = removeLeadTailQuotes(keys.substr(0, colonPos));
                            std::string value = removeLeadTailQuotes(keys.substr(colonPos + 1));
                            currentVarDic[key] = value;
                        }
                    }
                    currentVariable = true;
                }
            }
            else if (endVariableString == line.substr(0, line.find(' ')))
            {
                currentVariable = false;
                currentVarDic["content"] = currentContent;
                variables.push_back(currentVarDic);
                currentContent.clear();
            }
            else if (currentVariable)
            {
                currentContent += line;
                currentContent += "\n";
            }
        }
    }
}
