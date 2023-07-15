#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <cstddef>
#include <Extractor.h>
#include <CTextToCPP.h>

std::string CTextToCPP::writeDeclaration(const VariableStruct variable)
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

    declarationText.append("extern const char ");
    if (variable.seq != "RAWHEX")
    {
        declarationText.append("*const ");
    }
    else
    {
        declarationText.append("[]");
    }
    declarationText.append(variable.name + ";\n");

    return declarationText;
}

std::string CTextToCPP::writeImplementation(const VariableStruct variable)
{ // source stuff
    std::string sourceText;

    sourceText.append("extern const char ");
    if (variable.seq != "RAWHEX")
    {
        sourceText.append("*const ");
    }
    else
    {
        sourceText.append("[]");
    }
    sourceText.append(" = {\n");
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

CTextToCPP::CTextToCPP()
{
}