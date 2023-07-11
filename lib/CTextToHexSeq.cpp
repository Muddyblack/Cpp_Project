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

//test
int main()
{
    std::string text = "C++ ist eine von der ISO genormte Programmiersprache. Sie wurde ab 1979 von Bjarne Stroustrup bei AT&T als Erweiterung der Programmiersprache C entwickelt. C++ ermoeglicht sowohl die effiziente und maschinennahe Programmierung als auch eine Programmierung auf hohem Abstraktionsniveau. Der Standard definiert auch eine Standardbibliothek, zu der verschiedene Implementierungen existieren.";
    std::string hex = toHex(text);
    std::cout << hex;
    return 0;
}