#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>

class CTextToCPP
{
private:
    void generateCode(const std::string &inputFileName, const std::string &outputDir, const std::string &outputType);

public:
    CTextToCPP(const std::string &inputFilePath, const std::string &outputDir, const std::string &outputType);
    ~CTextToCPP();
};

#endif // CTEXTTOCPP_H
