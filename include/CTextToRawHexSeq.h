/**
 * @file CTextToRawHexSeq.h
 * @brief Contains the CTextToRawHexSeq class for converting text to raw hexadecimal sequences.
 */
#ifndef CTEXTTORAWHEXSEQ_H
#define CTEXTTORAWHEXSEQ_H

#include <CTextToCPP.h>

/**
 * @class CTextToRawHexSeq
 * @brief A class that converts text to raw hexadecimal sequences.
 *
 * This class inherits from the CTextToCPP class and provides an implementation to convert text
 * to raw hexadecimal sequences. It overrides the convert function to perform the conversion.
 */
class CTextToRawHexSeq : public CTextToCPP
{
public:
    /**
     * @brief Constructs a CTextToRawHexSeq object with the specified variable and parameter.
     * @param variable The VariableStruct object with the infos about the variable parameters
     * @param parameter The ParamStruct object with the infos of the @global tags from inputfile.
     */
    CTextToRawHexSeq(const VariableStruct &variable, const ParamStruct &parameter);
    /**
     * @brief Destroys the CTextToRawHexSeq object.
     */
    ~CTextToRawHexSeq();

private:
    /**
     * @brief Converts the input string to a raw hexadecimal sequence.
     *
     * This function converts the input string to a raw hexadecimal sequence by iterating over each character
     * in the string, checking for ASCII characters, and adding the corresponding hexadecimal representation to
     * the output stream. It also takes into account the variable line number, input file name, and new line character.
     *
     * @param inputString String that is being modified.
     * @param varLine Integer with the line Number of the variable
     * @param inputFile String with the Name of the inputFile
     * @param  nl New line character depending on os type
     * @return Modified ouput string with escape sequences.
     */
    std::string convert(std::string inputString, int varLine, std::string inputFile, std::string nl) override;
};

#endif // CTEXTTORAWHEXSEQ_H