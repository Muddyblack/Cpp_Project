#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <Parameter.h>
#include <vector>

class CTextToCPP
{
public:
    CTextToCPP(const std::string &PROJECT_PATH, std::string &inputFilePath, struct ParamStruct &parameter);
    ~CTextToCPP();
    void generateCode();

private:
    std::map<std::string, std::string> options;
    std::vector<std::map<std::string, std::string>> variables;
    struct ParamStruct parameter;
    std::string PROJECT_PATH;
    std::string inputFilePath;

    void printExtraction();

    void checkOptions();

    void writeDeclaration();
    void writeImplementation();
    void addElement();
    void sort();
    void clear();
};

#endif // CTEXTTOCPP_H