#include <string>

std::string toLowerCase(const std::string &str);
std::string toUpperCase(const std::string &str);

/**
 * Checks and edits a given file path.
 *
 * @param path The file path to check and edit.
 * @return The edited file path.
 */
std::string checkPath(const std::string &path);

/**
 * @brief Clears the console screen
 */
void clearConsole();