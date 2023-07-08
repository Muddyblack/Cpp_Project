#ifndef PARAMTER_H
#define PARAMTER_H

#include <string>
#include <iostream>

struct ParamStruct
{
    std::string outputDir;      /**< Output directory */
    std::string headerDir;      /**< Header file directory */
    std::string sourceDir;      /**< Source file directory */
    std::string outputType;     /**< Output file type (C or CPP) */
    std::string outputFilename; /**< Output filename (without extension) */
    std::string namespaceName;  /**< Namespace yes or no (only for CPP) */
    int signPerLine;            /**< Number of characters per line */
};

void printParamStruct(const ParamStruct &paramStruct);

#endif // PARAMETER_H
