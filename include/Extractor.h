#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <boost/tokenizer.hpp>

std::string stripString(const std::string &str);
std::string removeLeadTailQuotes(const std::string &str);
void extractOptionsAndVariables(const std::string &inputString, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables);

#endif // EXTRACTOR_H
