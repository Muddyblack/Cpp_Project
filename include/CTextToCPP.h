#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <Parameter.h>
#include <vector>

class CTextToCPP
{
public:
    CTextToCPP(const VariableStruct &variable);
    virtual ~CTextToCPP();

    void addElement(LinkedList *&head, std::string value);
    void sort();
    void clear();

    std::string writeDeclaration();
    std::string writeImplementation();

private:
    struct ParamStruct parameter;
    struct VariableStruct variable;

    virtual std::string convert(std::string inputString) = 0;

    std::string PROJECT_PATH;
    std::string inputFilePath;
};

#endif // CTEXTTOCPP_H