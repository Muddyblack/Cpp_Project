#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <Parameter.h>
#include <vector>

class CTextToCPP
{
public:
    CTextToCPP();
    ~CTextToCPP();

    void addElement(LinkedList *&head, std::string value);
    void sort();
    void clear();

    std::string writeDeclaration(const VariableStruct variable);
    std::string writeImplementation(const VariableStruct variable);

private:
    struct ParamStruct parameter;
    std::string PROJECT_PATH;
    std::string inputFilePath;
};

#endif // CTEXTTOCPP_H