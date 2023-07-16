/**
 * @file Helperfunctions.h
 * @brief Contains helper functions for string manipulation and console operations.
 */
#ifndef HELPER_H
#define HELPER_H

#include <string>

/**
 * @brief Change all Text to UpperCase
 * @param str a string with text
 * @return the string in UpperCase
 */
std::string toLowerCase(const std::string &str);

/**
 * @brief Change all Text to LowerCase
 * @param str a string with text
 * @return the string in LowerCase
 */
std::string toUpperCase(const std::string &str);

/**
 * Checks and edits a given file path for correct pattern.
 *
 * @param path The file path to check and edit.
 * @return The edited file path.
 */
std::string checkPath(const std::string &path);

/**
 * @brief Clears the console screen.
 *
 * This function clears the console screen by printing the appropriate escape sequences.
 */
void clearConsole();
#endif // HELPER_H