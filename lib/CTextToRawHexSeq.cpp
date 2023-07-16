#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToRawHexSeq.h>

/**
 * @brief converts ascii-string to raw hex
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

CTextToRawHexSeq::CTextToRawHexSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}
CTextToRawHexSeq::~CTextToRawHexSeq()
{
}