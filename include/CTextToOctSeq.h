/**
 * @file CTextToOctSeq.h
 * @brief Contains the CTextToOctSeq class for converting text to octal sequences.
 */

#ifndef CTEXTTOOCTSEQ_H
#define CTEXTTOOCTSEQ_H

#include <CTextToCPP.h>

/**
 * @class CTextToOctSeq
 * @brief A class that converts text to octal sequences.
 *
 * This class inherits from the CTextToCPP class and provides an implementation to convert text
 * to octal sequences. It overrides the convert function to perform the conversion.
 */
class CTextToOctSeq : public CTextToCPP
{
public:
    /**
     * @brief Constructs a CTextToOctSeq  object with the specified variable and parameter.
     * @param variable The VariableStruct object with the infos about the variable parameters
     * @param parameter The ParamStruct object with the infos of the @global tags from inputfile.
     */
    CTextToOctSeq(const VariableStruct &variable, const ParamStruct &parameter);

    /**
     * @brief Destroys the CTextToOctSeq object.
     */
    ~CTextToOctSeq();

private:
    /**
     * @brief Converts the input string to an octal sequence.
     *
     * This function converts the input string to an octal sequence by iterating over each character
     * in the string, checking for ASCII characters, and adding the corresponding octal representation
     * to the output stream. It also takes into account the variable line number, input file name, and
     * new line character.
     *
     * @param inputString String that is being modified.
     * @param varLine Integer with the line Number of the variable
     * @param inputFile String with the Name of the inputFile
     * @param  nl New line character depending on os type
     * @return Modified ouput string with escape sequences.
     */
    std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) override;
};

#endif // CTEXTTOOCTSEQ_H