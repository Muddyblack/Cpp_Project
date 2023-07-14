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

private:
    struct ParamStruct parameter;
    std::string PROJECT_PATH;
    std::string inputFilePath;

    void checkOptions();

    void writeDeclaration();
    void writeImplementation();
};

#endif // CTEXTTOCPP_H