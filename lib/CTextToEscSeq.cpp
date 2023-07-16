#include <iostream>
#include <iomanip>

/**
 * @brief replaces unprintable characters with escape-sequences
 */
std::string convert(std::string inputString, int lineNumber)
{
    std::stringstream stream;
    
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
        }
    }
    return stream.str();
}

//testing
int main()
{
    std::string a = "~a\"\n";
    std::string ausgabe = convert(a, 5);
    std::cout << ausgabe;
    return 0;
}
