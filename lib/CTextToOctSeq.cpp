#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToOctSeq.h>

/**
 * @brief converts ascii-string to octal
 */
std::string CTextToOctSeq::convert(std::string inputString)
{
    std::stringstream octStream;
    octStream << std::oct << std::setfill('0');
    for (char c : inputString)
    {
        octStream << "\\" << std::setw(3) << static_cast<int>(c);
    }
    return octStream.str();
}

CTextToOctSeq::CTextToOctSeq(const VariableStruct &variable) : CTextToCPP(variable)
{
    // constructor implementation
}

CTextToOctSeq::~CTextToOctSeq()
{
}