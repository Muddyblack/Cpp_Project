#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <boost/algorithm/string.hpp>

#include <CTextToCPP.h>

// Function to insert line breaks after certain amount of signs per line
std::vector<std::string> CTextToCPP::insertLineBreaks(const int &signPerLine, std::string &text, const std::string &nl, const std::string &seq)
{
    char seperator = ' ';
    std::string newLineChar = "\n";
    std::string returnChar = "\r";

    if (seq == "RAWHEX")
    {
        seperator = ',';
        // 0x0d = \r , 0x0a = \n
        newLineChar = "0x0a";
        returnChar = "0x0d";
    }
    else if (seq == "HEX")
    {
        seperator = '\\';
        // 0x0d = \r , 0x0a = \n
        newLineChar = "x0a";
        returnChar = "x0d";
    }
    else if (seq == "OCT")
    {
        seperator = '\\';
        // 0x0d = \r , 0x0a = \n
        newLineChar = "012";
        returnChar = "015";
    }

    std::string line;
    std::vector<std::string> result;
    int count = 0;

    std::vector<std::string> characters;
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, seperator))
    {
        characters.push_back(item);
    }

    bool dosNext = false;

    for (size_t i = 0; i < characters.size(); i++)
    {
        std::string currentItem = characters[i];
        boost::algorithm::trim(currentItem);

        std::string character;
        if ((seq == "HEX") || (seq == "OCT"))
        {
            if (i > 0)
            {
                character = seperator + currentItem;
            }
            else
            {
                character = currentItem;
            }
        }
        else
        {
            character = currentItem + seperator;
        }

        int lenghte = character.length();
        count += lenghte;

        if (count > signPerLine)
        {
            result.push_back(line);
            line = "";
            count = lenghte;
        }

        line.append(character);
        if ((nl == "DOS") && (currentItem == returnChar))
        {
            dosNext = true;
            continue;
        }

        if (((nl == "UNIX") && (currentItem == newLineChar)) || ((nl == "MAC") && (currentItem == returnChar)) || dosNext == true)
        {
            result.push_back(line);
            line = "";
            count = 0;
            dosNext = false;
        }
    }

    if ((seq == "ESC") || (seq == "RAWHEX"))
    {
        result[result.size() - 1].pop_back();
    }
    return result;
}

std::string CTextToCPP::writeDeclaration()
{ // header stuff
    std::string declarationText;

    // Check Doxgentext
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

std::string CTextToCPP::writeImplementation()
{ // source stuff
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
    std::string convertedContent = convert(variable.content); // have to adapt it to signperLine
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