#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <CTextToEscSeq.h>

/**
* @brief Function to convert escape characters to corresponding escape sequence
* @param input string that is being modified
* @return modified ouput string with escape sequences
 */
std::string CTextToEscSeq::convert(std::string inputString)
{
    // string for output text
    std::string output = "";
    // check each character in the input string and replace escape characters
    for (char c : inputString)
    {
        switch (c)
        {
        case '\a':
            output += "\\a";
            break;
        case '\b':
            output += "\\b";
            break;
        case '\e':
            output += "\\e";
            break;
        case '\f':
            output += "\\f";
            break;
        case '\n':
            output += "\\n";
            break;
        case '\r':
            output += "\\r";
            break;
        case '\t':
            output += "\\t";
            break;
        case '\v':
            output += "\\v";
            break;
        case '\\':
            output += "\\\\";
            break;
        case '\'':
            output += "\\'";
            break;
        case '\"':
            output += "\\\"";
            break;
        case '\?':
            output += "\\?";
            break;
        default:
            output += c;
            break;
        }
    }
    return output;
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
