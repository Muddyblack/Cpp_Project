#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

std::string toEsc(std::string inputString)
{
    std::string output = "";
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
