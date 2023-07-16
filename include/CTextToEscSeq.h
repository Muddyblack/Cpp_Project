/**
 * @file CTextToEscSeq.h
 * @brief Contains the CTextToEscSeq class for converting text to escape sequences.
 */

#ifndef CTEXTTOESCSEQ_H
#define CTEXTTOESCSEQ_H

#include <CTextToCPP.h>

/**
 * @class CTextToEscSeq
 * @brief A class that converts text to escape sequences.
 *
 * This class inherits from the CTextToCPP class and provides an implementation to convert text
 * to escape sequences. It overrides the convert function to perform the conversion.
 */
class CTextToEscSeq : public CTextToCPP
{
public:
    /**
     * @brief Constructs a CTextToEscSeq   object with the specified variable and parameter.
     * @param variable The VariableStruct object with the infos about the variable parameters
     * @param parameter The ParamStruct object with the infos of the @global tags from inputfile.
     */
    CTextToEscSeq(const VariableStruct &variable, const ParamStruct &parameter);
    ~CTextToEscSeq();

private:
    /**
     * @brief Converts the input string to escape sequences.
     *
     * This function converts the input string to escape sequences by iterating over each character
     * in the string, checking for ASCII characters, and replacing them with their corresponding escape
     * sequences. It also takes into account the variable line number, input file name, and new line character.
     *
     * @param inputString String that is being modified.
     * @param varLine Integer with the line Number of the variable
     * @param inputFile String with the Name of the inputFile
     * @param  nl New line character depending on os type
     * @return Modified ouput string with escape sequences.
     */
    std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) override;
};

#endif // CTEXTTOESCSEQ_H