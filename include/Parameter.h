/**
 * @file Parameter.h
 * @brief Contains structures and functions for handling parameters and variables.
 */

#ifndef PARAMTER_H
#define PARAMTER_H

#include <string>
#include <iostream>

/**
 * @struct ParamStruct
 * @brief Structure to hold parameter information.
 */
struct ParamStruct
{
    std::string headerDir;      /**< Header file directory */
    std::string sourceDir;      /**< Source file directory */
    std::string outputType;     /**< Output file type (C or CPP) */
    std::string outputFilename; /**< Output filename (without extension) */
    std::string namespaceName;  /**< Namespace yes or no (only for CPP) */
    int signPerLine = 0;        /**< Number of characters per line */
    bool sortByVarname = 0;     /**< sets if variable names should be sorted*/
};

/**
 * @brief Prints the information contained in a ParamStruct object.
 * @param paramStruct The ParamStruct object to print.
 */
void printParamStruct(const ParamStruct &paramStruct);

/**
 * @brief Structure to hold variable information.
 */
struct VariableStruct
{
    int VariableLineNumber; /**< This is the line where the variable has been defined in the input-File*/
    std::string name;       /**< Name of the variable */
    std::string seq;        /**< defines what Encoding should be used for the value (ESC, HEX, OCT, RAWHEX) */
    std::string nl;         /**< Sets how new line speration should be handled  (DOS = CR LF, MAC = CR, UNIX = LF)*/
    std::string content;    /** The content of the variable*/
    bool addtextpos;        /**< If true. The line of the variable of input-file will be included to the header*/
    bool addtextsegment;    /**< If true. Original text of variable will be added as comment*/
    std::string doxygen;    /**< Text for the doxygen*/
};

/**
 * @brief Prints the information contained in a VariableStruct object.
 * @param variableStruct The VariableStruct object to print.
 */
void printVariableStruct(const VariableStruct &variableStruct);

#endif // PARAMETER_H
