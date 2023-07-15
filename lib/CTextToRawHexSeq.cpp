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

//test
int main()
{
    std::string text = "Bruessel Europa bleibt voraussichtlich eine Rezession erspart, trotz Ukrainekrieg und Energiekrise. Allerdings droht der Kontinent gegenueber den dynamischeren USA und China weiter zurueckzufallen. Ein wichtiger Grund dafuer ist die schleppende wirtschaftliche Entwicklung in Deutschland. Die EU-Kommission hat ihre Wachstumsprognose fuer das laufende und das kommende Jahr am Montag leicht angehoben. Die Bruesseler Behoerde rechnet mit einem Plus von 1,0 Prozent fuer 2023 und 1,7 Prozent fuer 2024. Die europaeische Wirtschaft sei in besserer Verfassung als noch im Herbst angenommen, sagte EU-Wirtschaftskommissar Paolo Gentiloni.";
    std::string rawHex = toRawHex(text);
    std::cout << rawHex;
    return 0;
}