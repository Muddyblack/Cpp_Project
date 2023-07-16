#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

#include <boost/tokenizer.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <Extractor.h>

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

void extractOptionsAndVariables(const std::string &inputString, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables)
{
    boost::char_separator<char> newlineSeparator("\n");

    bool currentVariable = false;
    std::map<std::string, std::string> currentVarDic;
    std::string currentContent;
    bool work = false;

    const std::string startString = "@start";
    const std::string endString = "@end";
    const std::string globalString = "@global";
    const std::string variableString = "@variable";
    const std::string endVariableString = "@endvariable";

    int lineNumber = 0;
    std::istringstream iss(inputString);
    std::string line;

    while (std::getline(iss, line))
    {
        lineNumber++;

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
                    std::string variableString = line.substr(startPos, endPos - startPos + 1);

                    std::map<std::string, std::string> tempOptions = parseJsonString(variableString);
                    options.insert(tempOptions.begin(), tempOptions.end());
                }
            }
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
            else if (endVariableString == line.substr(0, line.find(' ')) && currentVariable == true)
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
