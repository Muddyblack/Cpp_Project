/**
 * @file ConsoleColors.h
 * @brief Contains escape sequences for console colors.
 */

#ifndef CONSOLE_COLORS_H
#define CONSOLE_COLORS_H

#include <iostream>
#include <string>

// Function to enable support for ANSI escape sequences in Windows console
#ifdef _WIN32
#include <windows.h> // Include the Windows header

void EnableConsoleColors()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
void EnableConsoleColors()
{
}
#endif

const std::string RESET_COLOR = "\033[0m";           /**< Reset color escape sequence */
const std::string GREEN_COLOR = "\033[32m";          /**< Green color escape sequence */
const std::string RED_COLOR = "\033[31m";            /**< Red color escape sequence */
const std::string ORANGE_COLOR = "\033[38;5;208m";   /**< Orange color escape sequence */
const std::string CYAN_COLOR = "\033[36m";           /**< Cyan color escape sequence */
const std::string BLACK_COLOR = "\033[30m";          /**< Black color escape sequence */
const std::string BLUE_COLOR = "\033[38;5;19m";      /**< Blue color escape sequence */
const std::string STRONG_GREEN_COLOR = "\033[1;32m"; /**< Strong green color escape sequence */

#endif
