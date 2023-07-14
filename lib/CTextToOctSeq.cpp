#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief converts ascii-string to octal
 */
std::string toOct(std::string inputString)
{
    std::stringstream octStream;
    octStream << std::oct << std::setfill('0');
    for (char c : inputString)
    {
        octStream << "\\" << std::setw(3) << static_cast<int>(c);
    }
    return octStream.str();
}