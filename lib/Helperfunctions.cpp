#include <iostream>
#include <filesystem>

#include <Helperfunctions.h>

/**
 * @brief Change all Text to UpperCase
 * @param str a string with text
 * @return the string in UpperCase
 */
std::string toUpperCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::toupper(c);
    }
    return result;
}

/**
 * @brief Change all Text to LowerCase
 * @param str a string with text
 * @return the string in LowerCase
 */
std::string toLowerCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

/**
 * @brief check if the path is correct
 * @param path
 * @return modified path, if needed
 */
std::string checkPath(const std::string &path)
{
    std::filesystem::path fsPath(path);

    // Special cases: "." and "directiry" are considered relative paths
    if (fsPath == "." || fsPath == "directiry")
    {
        fsPath = std::filesystem::current_path();
    }
    else if (!fsPath.is_absolute())
    {
        fsPath = std::filesystem::absolute(fsPath);
    }

    std::string sanitizedPath = fsPath.string();

    // Replace forward slashes and single backslashes with double backslashes
    size_t found = sanitizedPath.find_first_of("/\\");
    while (found != std::string::npos)
    {
        sanitizedPath.replace(found, 1, "\\\\");
        found = sanitizedPath.find_first_of("/\\", found + 2);
    }

    return sanitizedPath;
}
/**
 * @brief clears the console
 */
void clearConsole()
{
    std::cout << "\033[2J\033[1;1H";
}