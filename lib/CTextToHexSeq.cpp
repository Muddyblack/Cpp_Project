#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToHexSeq.h>

/**
 * @brief converts ascii-string to hex
 */
std::string CTextToHexSeq::convert(std::string inputString, int varLine, std::string inputFile, std::string nl)
{

    std::stringstream stream;
    stream << std::hex << std::setfill('0');
    unsigned int charPos = 0;

    // checkNewLine(inputString, nl);

    for (unsigned char c : inputString)
    {
        checkASCII(c, varLine, charPos, inputFile);

        stream << "\\x" << std::setw(2) << static_cast<int>(c);
        charPos++;
    }
    return stream.str();
}

CTextToHexSeq::CTextToHexSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

CTextToHexSeq::~CTextToHexSeq()
{
    // destructor implementation
}
