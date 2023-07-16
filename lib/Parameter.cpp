#include <Parameter.h>
#include <ConsoleColors.h>

void printParamStruct(const ParamStruct &paramStruct)
{
    std::cout << "Program arguments:\n";
    std::cout << "Header Directory: " << CYAN_COLOR << paramStruct.headerDir << RESET_COLOR << std::endl;
    std::cout << "Source Directory: " << CYAN_COLOR << paramStruct.sourceDir << RESET_COLOR << std::endl;
    std::cout << "Output Type: " << CYAN_COLOR << paramStruct.outputType << RESET_COLOR << std::endl;
    std::cout << "Output Filename: " << CYAN_COLOR << paramStruct.outputFilename << RESET_COLOR << std::endl;
    std::cout << "Namespace Name: " << CYAN_COLOR << (paramStruct.namespaceName) << RESET_COLOR << std::endl;
    std::cout << "Sign Per Line: " << CYAN_COLOR << paramStruct.signPerLine << RESET_COLOR << std::endl;
    std::cout << "Sort By Variable Name: " << CYAN_COLOR << paramStruct.sortByVarname << RESET_COLOR << std::endl;
    std::cout << std::endl;
}

void printParamStruct(const VariableStruct &variableStruct)
{
    std::cout << "Program variable: "<< BLUE_COLOR << variableStruct.name << RESET_COLOR << "\n";
    std::cout << "Add the text position: " << CYAN_COLOR << variableStruct.addtextpos << RESET_COLOR << std::endl;
    std::cout << "Add the text segment: " << CYAN_COLOR << variableStruct.addtextsegment << RESET_COLOR << std::endl;
    std::cout << "The Doxygentext: " << CYAN_COLOR << variableStruct.doxygen << RESET_COLOR << std::endl;
    std::cout << "The New Line Seperator: " << CYAN_COLOR << variableStruct.nl << RESET_COLOR << std::endl;
    std::cout << "Variables Content: " << CYAN_COLOR << variableStruct.content << RESET_COLOR << std::endl;
    std::cout << "The Encoding Type: " << CYAN_COLOR << variableStruct.seq << RESET_COLOR << std::endl;
    std::cout << std::endl;
}

void printLinkedList(LinkedList *head)
{
    LinkedList *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << "\n";
        current = current->next;
    }
    std::cout << std::endl;
}