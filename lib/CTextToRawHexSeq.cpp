#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToRawHexSeq.h>

/**
 * @brief Converts ascii-string to raw hexadicimal sequence.
 * @param inputString ASCII string to be converted.
 * @return rawHexStream Content of the rawHexStream as string.
 */
std::string CTextToRawHexSeq::convert(std::string inputString)
{
    std::stringstream rawHexStream;
    rawHexStream << std::hex << std::setfill('0');
    for (char c : inputString)
    {
        rawHexStream << "0x" << std::setw(2) << static_cast<int>(c) << ", ";
    }
    return rawHexStream.str();
}

// constructor to initialize an instance of the CTextToRawHexSeq class
CTextToRawHexSeq::CTextToRawHexSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

// destructor for the CTextToRawHexSeq class
CTextToRawHexSeq::~CTextToRawHexSeq()
{
}