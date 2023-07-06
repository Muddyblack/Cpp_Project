#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <string>
#include <map>
#include <vector>

/**
 * @brief Parses a JSON string and returns a dictionary containing key-value pairs.
 *
 * @param jsonString The JSON string to parse.
 * @return The dictionary containing the parsed key-value pairs.
 */
std::map<std::string, std::string> parseJsonString(const std::string &jsonString);

/**
 * Extracts options and variables from an input string and populates the provided maps and vector.
 *
 * @param inputString The input string containing options and variables.
 * @param options The map to store extracted options (key-value pairs).
 * @param variables The vector of maps to store extracted variables (key-value pairs).
 */
void extractOptionsAndVariables(const std::string &inputString, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables);

#endif // EXTRACTOR_H
