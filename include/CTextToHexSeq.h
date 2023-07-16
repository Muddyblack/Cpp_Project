/**
 * @file CTextToHexSeq.h
 * @brief Contains the CTextToHexSeq class for converting text to hexadecimal sequences.
 */

#ifndef CTEXTTOHEXSEQ_H
#define CTEXTTOHEXSEQ_H

#include <CTextToCPP.h>

/**
 * @class CTextToHexSeq
 * @brief A class that converts text to hexadecimal sequences.
 *
 * This class inherits from the CTextToCPP class and provides an implementation to convert text
 * to hexadecimal sequences. It overrides the convert function to perform the conversion.
 */
class CTextToHexSeq : public CTextToCPP
{
public:
    /**
     * @brief Constructs a CTextToHexSeq   object with the specified variable and parameter.
     * @param variable The VariableStruct object with the infos about the variable parameters
     * @param parameter The ParamStruct object with the infos of the @global tags from inputfile.
     */
    CTextToHexSeq(const VariableStruct &variable, const ParamStruct &parameter);

    /**
     * @brief Destroys the CTextToHexSeq object.
     */
    ~CTextToHexSeq();

private:
    /**
     * @brief Converts the input string to a hexadecimal sequence.
     *
     * This function converts the input string to a hexadecimal sequence by iterating over each character
     * in the string, checking for ASCII characters, and adding the corresponding hexadecimal representation
     * to the output stream. It also takes into account the variable line number, input file name, and
     * new line character.
     *
     * @param inputString String that is being modified.
     * @param varLine Integer with the line Number of the variable
     * @param inputFile String with the Name of the inputFile
     * @param  nl New line character depending on os type
     * @return Modified ouput string with escape sequences.
     */
    std::string convert(std::string &inputString, const int &varLine, const std::string &inputFile, const std::string &nl) override;
};

#endif // CTEXTTOHEXSEQ_H