#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief converts ascii-string to raw hex
 */
std::string toRawHex(std::string inputString)
{
    std::stringstream rawHexStream;
    rawHexStream << std::hex << std::setfill('0');
    for (char c : inputString)
    {
        rawHexStream << "0x" << std::setw(2) << static_cast<int>(c) << ", ";
    }
    return rawHexStream.str();
}