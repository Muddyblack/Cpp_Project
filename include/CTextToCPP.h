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
    struct ParamStruct parameter;
    std::string PROJECT_PATH;
    std::string inputFilePath;

    void checkOptions();

    void writeDeclaration();
    void writeImplementation();
    void addElement();
    void sort();
    void clear();
};

#endif // CTEXTTOCPP_H