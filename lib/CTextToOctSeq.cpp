#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToOctSeq.h>

/**
 * @brief Converts ascii-string to octal sequence.
 * @param inputString ASCII string to be converted.
 * @return octStream Content of the octStream as string.
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

// constructor to initialize an instance of the CTextToOctSeq class
CTextToOctSeq::CTextToOctSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

// destructor for the CTextToOctSeq class
CTextToOctSeq::~CTextToOctSeq()
{
}