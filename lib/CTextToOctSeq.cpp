#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToOctSeq.h>

/**
 * @brief converts ascii-string to octal
 */
std::string CTextToOctSeq::convert(std::string inputString, int varLine, std::string inputFile, std::string nl)
{
    std::stringstream stream;
    stream << std::oct << std::setfill('0');
    unsigned int charPos = 0;

    // checkNewLine(inputString, nl);

    for (unsigned char c : inputString)
    {
        checkASCII(c, varLine, charPos, inputFile);

        stream << "\\" << std::setw(3) << static_cast<int>(c);
        charPos++;
    }
    return stream.str();
}

CTextToOctSeq::CTextToOctSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

CTextToOctSeq::~CTextToOctSeq()
{
}