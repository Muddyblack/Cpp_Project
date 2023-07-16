/**
 * @file CTextToCPP.h
 * @brief Contains the CTextToCPP class for text-to-C++ conversion.
 */

#ifndef CTEXTTOCPP_H
#define CTEXTTOCPP_H

#include <string>
#include <map>
#include <Parameter.h>
#include <vector>
struct Node
{
    std::string data; // Elements
    Node *next;
};

/**
 * * @class CTextToCPP
 * @brief Base class for data management.
 *
 * This class provides the base functionality for converting text to C++ code and managing data.
 * It includes functions for checking ASCII characters, handling new line characters, adding elements to a linked list,
 * sorting elements, clearing the linked list, generating declaration and implementation texts, and inserting line breaks in the text.
 * It is intended to be inherited by derived classes that implement specific text-to-C++ conversion functionality.
 */
class CTextToCPP
{
protected:
    /**
     * @brief Checks if the input character is an ASCII character and raises an error if it's not.
     *
     * @param input The input character to check.
     * @param line The line number of the variable in the input file.
     * @param pos The position of the character in the variable-part string.
     * @param inputFile The name of the input file.
     */
    void checkASCII(const unsigned char &input, const int &line, const unsigned int &pos, const std::string &inputFile);

    /**
     * @brief Checks and handles the presence of new line characters in the input string.

    * @param input The input string to check and modify.
    * @param nl The new line character depending on the operating system type.
    */
    void checkNewLine(std::string &input, const std::string &nl);

public:
    /**
     * @brief Constructor for the CTextToCPP class that takes a VariableStruct object and a ParamStruct object as arguments.
     *
     * @param variable The VariableStruct object representing the variable.
     * @param parameter The ParamStruct object representing the parameter.
     */
    CTextToCPP(const VariableStruct &variable, const ParamStruct &parameter);
    /**
     * @brief Destructor for the CTextToCPP class.
     */
    virtual ~CTextToCPP();

    /**
     * @brief Function for adding a new element to the LinkedList.
     *
     * @param head A pointer to the head node of the linked list.
     * @param value  value
     */
    void addElement(Node *&head, std::string value);

    /**
     * @brief Function to sort elements of the LinkedList alphabetically.
     *
     * @param head A pointer to the head node of the linked list.
     */
    void sort(Node **head);

    /**
     * @brief Function to delete all elements of the LinkedList
     *
     * @param head A pointer to the head node of the linked list.
     */
    void clear(Node *&head);

    /**
     *@brief Function to generate the declaration text for the input file.
     *
     * This function generates the declaration text for the input file.
     * It constructs the declaration code based on the variable name, type, and other options.
     * If a doxygen comment is provided for the variable, it is included in the declaration.
     *
     * @return Declaration text.
     */
    std::string writeDeclaration();
    /**
     * @brief Function to generate the source text for the input file.
     *
     * @return The generated Source text.
     */
    std::string writeImplementation();

private:
    /**
     * @brief Contains the @global options.
     */
    struct ParamStruct parameter;
    /**
     * @brief Contains the @variable parameters.
     */
    struct VariableStruct variable;

    /**
     * @brief Pure virtual function to convert the input string to the desired format.
     *
     * This function is a pure virtual function that needs to be implemented by derived classes.
     * It converts the input string to the desired format (escape sequence, hex sequence, octal sequence, etc.),
     * taking into account the variable line number, input file name, and new line character.
     *
     * @param inputString String that is being modified.
     * @param varLine Integer with the line Number of the variable
     * @param inputFile String with the Name of the inputFile
     * @param  nl New line character depending on os type
     *
     * @return The modified output string with the desired format.
     */
    virtual std::string convert(std::string &inputString, const int &varLine, const std::string &inputFile, const std::string &nl) = 0;

    /**
     * @brief Function to insert line breaks after certain amount of signs per line.
     *
     * @param signPerLine Number of signs per line.
     * @param text Text to be processed.
     * @param  nl New line character depending on os type
     * @param seq Type of text.
     * @return The modified text with each line not longer than the given number of signs per line.
     */
    std::vector<std::string> insertLineBreaks(const int &signPerLine, const std::string &text, const std::string &nl, const std::string &seq);

    /**
     * @brief Represents project path.
     */
    std::string PROJECT_PATH;

    /**
     * @brief Represents input file path.
     */
    std::string inputFilePath;
};

#endif // CTEXTTOCPP_H