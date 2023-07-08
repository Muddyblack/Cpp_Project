#ifndef PARAMTER_H
#define PARAMTER_H

#include <string>
#include <iostream>

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

void printParamStruct(const ParamStruct &paramStruct);

struct VariableStruct
{
    int VariableLineNumber; /**< This is the line where the variable has been defined in the input-File*/
    std::string name;       /**< Name of the variable */
    std::string seq;        /**< defines what Encoding should be used for the value (ESC, HEX, OCT, RAWHEX) */
    std::string nl;         /**< Sets how new line speration should be handled  (DOS = CR LF, MAC = CR, UNIX = LF)*/
    bool addtextpos;        /**< If true. The line of the variable of input-file will be included to the header*/
    bool addtextsegment;    /**< If true. Original text of variable will be added as comment*/
    std::string doxygen;    /**< Text for the doxygen*/
};

void printVariableStruct(const VariableStruct &variableStruct);

#endif // PARAMETER_H
