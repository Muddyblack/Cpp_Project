#ifndef EXTRACTOR_H
#define EXTRACTOR_H

std::string stripString(const std::string &str);

std::string removeLeadTailQuotes(const std::string &str);

void extractOptionsAndVariables(const std::string &inputString, std::map<std::string, std::string> &options, std::vector<std::map<std::string, std::string>> &variables);

#endif // EXTRACTOR_H
