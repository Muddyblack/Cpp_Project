#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <Parameter.h>
#include <vector>

class CTextToCPP
{
protected:
    void checkASCII(unsigned char &input, int &line, unsigned int &pos, std::string &inputFile);
    void checkNewLine(std::string &input, const std::string &nl);

public:
    CTextToCPP(const VariableStruct &variable, const ParamStruct &parameter);
    virtual ~CTextToCPP();

    void addElement(LinkedList *&head, std::string value);
    void sort();
    void clear();

    std::string writeDeclaration();
    std::string writeImplementation();

private:
    struct ParamStruct parameter;
    struct VariableStruct variable;

    virtual std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) = 0;
    std::vector<std::string> insertLineBreaks(const int &signPerLine, std::string &text, const std::string &nl, const std::string &seq);

    std::string PROJECT_PATH;
    std::string inputFilePath;
};

#endif // CTEXTTOCPP_H