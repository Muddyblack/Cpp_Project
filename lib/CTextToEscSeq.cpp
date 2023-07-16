#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <CTextToEscSeq.h>

std::string CTextToEscSeq::convert(std::string inputString, int varLine, std::string inputFile, std::string nl)
{
    std::stringstream stream;
    unsigned int charPos = 0;
    checkNewLine(inputString, nl);
    // check each character in the input string and replace escape characters
    for (unsigned char c : inputString)

    {
        checkASCII(c, varLine, charPos, inputFile);

        switch (c)
        {
        case '\a':
            stream << "\\a";
            break;
        case '\b':
            stream << "\\b";
            break;
        case '\e':
            stream << "\\e";
            break;
        case '\f':
            stream << "\\f";
            break;
        case '\n':
            stream << "\\n";
            break;
        case '\r':
            stream << "\\r";
            break;
        case '\t':
            stream << "\\t";
            break;
        case '\v':
            stream << "\\v";
            break;
        case '\\':
            stream << "\\\\";
            break;
        case '\'':
            stream << "\\'";
            break;
        case '\"':
            stream << "\\\"";
            break;
        case '\?':
            stream << "\\?";
            break;
        default:
            stream << c;
            break;
        }
        charPos++;
    }
    return stream.str();
}

// constructor to initialize an instance of the CTextToEscSeq class
CTextToEscSeq::CTextToEscSeq(const VariableStruct &variable, const ParamStruct &parameter) : CTextToCPP(variable, parameter)
{
    // constructor implementation
}

// destructor for the CTextToEscSeq class
CTextToEscSeq::~CTextToEscSeq()
{
    // destructor implementation
}
