#include <iostream>
#include <sstream>
#include <iomanip>

#include <CTextToOctSeq.h>

/**
 * @brief Converts ascii-string to octal sequence.
 * @param inputString ASCII string to be converted.
 * @return octStream Content of the octStream as string.
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

// constructor to initialize an instance of the CTextToOctSeq class
CTextToOctSeq::CTextToOctSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

// destructor for the CTextToOctSeq class
CTextToOctSeq::~CTextToOctSeq()
{
}