#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <boost/algorithm/string.hpp>

#include <Logger.h>
#include <ConsoleColors.h>

#include <CTextToCPP.h>


void CTextToCPP::checkASCII(unsigned char &input, int &line, unsigned int &pos, std::string &inputFile)
{
    int value = static_cast<int>(input);
    if (value >= 0x80)
    {
        BOOST_LOG_TRIVIAL(fatal) << RED_COLOR << "ASCII ERROR in: " << BLUE_COLOR << inputFile << RED_COLOR
                                 << " in line: " << line << ORANGE_COLOR << " it is the: " << pos << " character" << RESET_COLOR << std::endl;
        exit(1);
    }
}

void CTextToCPP::checkNewLine(std::string &input, const std::string &nl)
{
    int width = 1;
    std::string newLineSeperator;

    if (nl == "DOS")
    {
        width = 2;
        newLineSeperator = "\r\n";
    }
    else if (nl == "MAC")
    {
        newLineSeperator = "\r";
    }
    else if (nl == "UNIX")
    {
        newLineSeperator = "\n";
    }

    if (input.substr((input.length() - width)) == newLineSeperator)
    {
        input.erase((input.length() - 8));
    }
}

// Function to insert line breaks after certain amount of signs per line
std::vector<std::string> CTextToCPP::insertLineBreaks(const int &signPerLine, std::string &text, const std::string &nl, const std::string &seq)
{
    char separator = ' ';
    std::string newLineChar = "\\n";
    std::string returnChar = "\\r";

    /**
    * @brief Assign characters for separation, new line and carriage return for each text type.
    */
    if (seq == "RAWHEX")
    {
        separator = ',';
        newLineChar = "0x0a";
        returnChar = "0x0d";
    }
    else if (seq == "HEX")
    {
        separator = '\\';
        newLineChar = "x0a";
        returnChar = "x0d";
    }
    else if (seq == "OCT")
    {
        separator = '\\';
        newLineChar = "012";
        returnChar = "015";
    }


    std::vector<std::string> result;
    std::string line;

    int count = 0;

    /**
    * @brief Vector for extracted substrings.
    */
    std::vector<std::string> characters;
    /**
    * @brief Stringstream object with text.
    */
    std::stringstream ss(text);
    /**
    * @brief Text between separation characters.
    */
    std::string item;


    /**
    * @brief Extract substrings from text using separator as delimiter and adding them to characters.
    */
    while (std::getline(ss, item, seperator))

    {
        if (seq == "ESC")
        {
            std::vector<size_t> positions;
            for (size_t i = 0; i < item.size(); ++i)
            {
                std::string complete = item.substr(i, 2);
                if (complete == newLineChar || complete == returnChar)
                {
                    positions.push_back(i);
                    i += 1;
                }
            }

            size_t startPos = 0;
            for (size_t pos : positions)
            {
                characters.push_back(item.substr(startPos, pos - startPos));
                characters.push_back(item.substr(pos, 2)); // Add the line break character as a separate substring
                startPos = pos + 2;
            }

            if (startPos < item.size())
            {
                characters.push_back(item.substr(startPos));
            }
        }
        else
        {
            characters.push_back(item);
        }
    }

    bool dosNext = false;

    /**
    * @brief Iteration over characters without leading and trailing whitespaces.
    * Construct the character string depending on the value of seq.
    * For octal and hexadecimals join the current item together with the separator character except the last item.
    * Then count the length of the appendet character and check if exceeds the number of signs per line.
    * New lines are added according to the os type.
    */
    for (size_t i = 0; i < characters.size(); i++)
    {
        std::string currentItem = characters[i];
        boost::algorithm::trim(currentItem);

        std::string character;
        if ((seq == "HEX" || seq == "OCT"))
        {
            if (i > 0)
            {
                character = separator + currentItem;
            }
            else
            {
                character = currentItem;
            }
        }
        else if (seq == "ESC" && (currentItem == newLineChar || currentItem == returnChar))
        {
            character = currentItem;
        }
        else
        {
            character = (i < characters.size() - 1) ? currentItem + separator : currentItem;
        }

        int length = character.length();
        count += length;

        if (count > signPerLine)
        {
            result.push_back(line);
            line = "";
            count = length;
        }

        line.append(character);
        if ((nl == "DOS" && currentItem == returnChar))
        {
            dosNext = true;
            continue;
        }

        if ((nl == "UNIX" && currentItem == newLineChar) || (nl == "MAC" && currentItem == returnChar) || dosNext)
        {
            result.push_back(line);
            line = "";
            count = 0;
            dosNext = false;
        }
    }

    return result;
}

/**
* @brief Function to generate content of header file.
* @return declarationText Text to be declared in header file.
*/
std::string CTextToCPP::writeDeclaration()
{ // header stuff
    /**
    * @brief Holds the generated declaration code.
    */
    std::string declarationText;

    // Check Doxygentext
    if (!variable.doxygen.empty())
    {
        declarationText.append("/** " + variable.doxygen);
        if (variable.addtextpos)
        {
            declarationText.append(" (aus Zeile" + std::to_string(variable.VariableLineNumber) + " ) ");
        }
        declarationText.append("*/\n");
    }

    declarationText.append("const char ");
    if (variable.seq != "RAWHEX")
    {
        declarationText.append("*const ");
    }
    declarationText.append(variable.name);

    if (variable.seq == "RAWHEX")
    {
        declarationText.append("[]");
    }
    declarationText.append(";\n");

    return declarationText;
}


/**
* @brief Function to generate text of the source file.
* The text is to be converted and new lines are to be inserted.
* @return Source text.
*/
std::string CTextToCPP::writeImplementation()
{ // source stuff
    /**
    * @brief Holds the generated source code.
    */
    std::string sourceText;

    sourceText.append("const char ");
    if (variable.seq != "RAWHEX")
    {
        sourceText.append("*const ");
    }

    sourceText.append(variable.name);
    if (variable.seq == "RAWHEX")
    {
        sourceText.append("[]");
    }

    sourceText.append(" = {\n");
    std::string convertedContent = convert(variable.content, variable.VariableLineNumber, parameter.outputFilename, variable.nl);
    std::vector<std::string> adoptedContent = insertLineBreaks(parameter.signPerLine, convertedContent, variable.nl, variable.seq);

    for (std::string line : adoptedContent)
    {
        std::string quotes = "\"";
        if (variable.seq == "RAWHEX")
        {
            quotes = "";
        }
        sourceText.append(quotes + line + quotes + " \\\n");
    }
    /*
    +
    +   Missing content of variable
    +
    */
    sourceText.append("};\n");

    if (variable.addtextsegment)
    {
        std::string originalTextComment = "/*\nOriginaltext aus der Variablensektion '" + variable.name + "'\n\n" + variable.content + "*/\n";
        sourceText.append(originalTextComment);
    }

    return sourceText;
}


/**
* @brief Function to add elements to a linked list by a pointer to the head node.
* @param *&head pointer to head node
* @param string value 
*/
void CTextToCPP::addElement(LinkedList *&head, std::string value)
{
    if (head == nullptr)
    {
        // The list is empty, create a new head node
        head = new LinkedList{value, nullptr};
    }
    else
    {
        // Traverse the list to find the last node
        LinkedList *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        // Create a new node and link it to the last node
        current->next = new LinkedList{value, nullptr};
    }
}

void CTextToCPP::sort()
{
    std::cout << "Hiii" << std::endl;
}

void CTextToCPP::clear()
{
    std::cout << "Hiii" << std::endl;
}

CTextToCPP::~CTextToCPP()
{
}

CTextToCPP::CTextToCPP(const VariableStruct &variable, const ParamStruct &parameter) : parameter(parameter), variable(variable)
{
}