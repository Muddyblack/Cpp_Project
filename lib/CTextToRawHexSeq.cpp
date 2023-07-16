#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToRawHexSeq.h>

/**
 * @brief converts ascii-string to raw hex
 */
std::string CTextToRawHexSeq::convert(std::string inputString, int varLine, std::string inputFile, std::string nl)
{
    std::stringstream stream;
    stream << std::hex << std::setfill('0');
    unsigned int charPos = 0;
    // checkNewLine(inputString, nl);

    bool firstElement = true;

    for (unsigned char c : inputString)
    {
        checkASCII(c, varLine, charPos, inputFile);

        if (!firstElement)
            stream << ", "; // Add a comma and space before elements except for the first one
        else
            firstElement = false;

        stream << "0x" << std::setw(2) << static_cast<int>(c);
        charPos++;
    }
    return stream.str();
}

CTextToRawHexSeq::CTextToRawHexSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}
CTextToRawHexSeq::~CTextToRawHexSeq()
{
}