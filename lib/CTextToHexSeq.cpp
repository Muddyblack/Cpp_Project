#include <iostream>
#include <iomanip>
#include <fstream>


/**
 * @brief converts ascii-string to hex
 */
std::string convert(std::string inputString, int lineNumber)
{
    std::stringstream stream;
    stream << std::hex << std::setfill('0');

    //removeNewline, kann man aus CTextToCPP erben
    if(inputString.substr(inputString.length()-1) == "\n")
    {
        inputString.erase(inputString.length()-1);
    }

    for (unsigned char c : inputString)
    {
        int a = static_cast<int>(c);

        //checks if character is representable, kann man auch aus CTextToCPP erben
        if(a >= 0x80)
        {
            //Error not representable
            std::ostringstream errorMessage;
            errorMessage << "Character in line " << lineNumber << " not representable";
            throw std::runtime_error(errorMessage.str());
        }
        else
        {
            stream << "\\x" << std::setw(2) << static_cast<int>(c);
        }
    }
    return stream.str();
}

//testing
int main()
{
    std::ifstream file("C:/hex.txt"); // Dateinamen anpassen
    std::string content;
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    }
    std::string esc = convert(content, 5);
    std::cout << esc;
    return 0;
}