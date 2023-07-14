#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief converts ascii-string to hex
 */
std::string toHex(std::string inputString)
{
    std::stringstream hexStream;
    hexStream << std::hex << std::setfill('0');
    for (char c : inputString)
    {
        hexStream << "\\x" << std::setw(2) << static_cast<int>(c);
    }
    return hexStream.str();
}