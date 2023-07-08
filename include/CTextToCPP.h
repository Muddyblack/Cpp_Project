#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <vector>

class CTextToCPP
{
public:
    CTextToCPP(std::string &inputFilePath, struct ParamStruct &parameter);
    ~CTextToCPP();
    void generateCode();

private:
    std::map<std::string, std::string> options;
    std::vector<std::map<std::string, std::string>> variables;
    void printExtraction();
};

#endif // CTEXTTOCPP_H