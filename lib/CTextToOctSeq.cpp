#include <iostream>
#include <sstream>
#include <iomanip>
#include <boost/format.hpp>

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

int main()
{
    std::string text = "The quick brown fox jumps over the Lazy dog ... Das ist eine typische Testsequence fuer Texte (und um auch eine 'Datenstrecke' zu ueberpruefen).";
    std::string oct = toOct(text);
    std::cout << oct;
    return 0;
}