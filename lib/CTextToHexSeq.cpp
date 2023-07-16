#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToHexSeq.h>

/**
 * @brief converts ascii-string to hex
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

CTextToHexSeq::CTextToHexSeq(const VariableStruct &variable) : CTextToCPP(variable)
{
    // constructor implementation
}

CTextToHexSeq::~CTextToHexSeq()
{
    // destructor implementation
}
