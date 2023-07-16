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
 * @brief Base class for data management.
 */
class CTextToCPP
{
protected:
    void checkASCII(unsigned char &input, int &line, unsigned int &pos, std::string &inputFile);
    void checkNewLine(std::string &input, const std::string &nl);

public:
    /**
     * @brief Constructor for the CTextToCPP class that takes a VariableStruct object and a ParamStruct object as arguments.
     */
    CTextToCPP(const VariableStruct &variable, const ParamStruct &parameter);
    /**
     * @brief Destructor for the CTextToCPP class.
     */
    virtual ~CTextToCPP();

    /**
     * @brief Function for adding a new element to the LinkedList.
     * @param *&head pointer to head node
     * @param string value
     */
    void addElement(Node *&head, std::string value);
    /**
     * @brief Function to sort elements alphabetically.
     */
    void sort(Node **head);
    /**
     * @brief Function to delete all elements.
     */
    void clear(Node *&head);

    /**
     * @brief Function to generate declaration text.
     * @return Declaration text.
     */
    std::string writeDeclaration();
    /**
     * @brief Function to generate source text.
     * @return Source text.
     */
    std::string writeImplementation();

private:
    /**
     * @brief Contains options.
     */
    struct ParamStruct parameter;
    /**
     * @brief Contains variable parameters.
     */
    struct VariableStruct variable;

    /**
     * @brief Function to convert escape characters to corresponding escape sequence.
     * @param inputString String that is being modified.
     * @return Modified ouput string with escape sequences.
     */
    virtual std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) = 0;

    /**
     * @brief Function to insert line breaks after certain amount of signs per line.
     * @param signPerLine Number of signs per line.
     * @param text Text to be processed.
     * @param  nl New line character depending on os type
     * @param seq Type of text.
     * @return Text with each line not longer than the given number of signs per line.
     */
    std::vector<std::string> insertLineBreaks(const int &signPerLine, std::string &text, const std::string &nl, const std::string &seq);

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