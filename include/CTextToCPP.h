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

    void addElement(LinkedList *&head, std::string varname, std::string content);
    void sort(LinkedList *&head, std::string varname, std::string content);
    void clear();

    std::string writeDeclaration(const VariableStruct variable);
    std::string writeImplementation(const VariableStruct variable);
    //std::string removeNewline(std::string input);

private:
    struct ParamStruct parameter;
    std::string PROJECT_PATH;
    std::string inputFilePath;
};

#endif // CTEXTTOCPP_H