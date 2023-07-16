#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToHexSeq.h>

/**
 * @brief Converts ascii-string to hex.
 * @param inputString ASCII string to be converted.
 * @return hexStream Content of the hexStream as string.
 */
std::string CTextToHexSeq::convert(std::string inputString)
{
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (char c : inputString)
    {
        hexStream << "\\x" << std::setw(2) << static_cast<int>(c);
    }
    return hexStream.str();
}

// constructor to initialize an instance of the CTextToEscSeq class
CTextToHexSeq::CTextToHexSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

// destructor for the CTextToHexSeq class
CTextToHexSeq::~CTextToHexSeq()
{
    // destructor implementation
}
