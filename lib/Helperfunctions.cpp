#include <iostream>
#include <filesystem>

#include <Helperfunctions.h>

std::string toUpperCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::toupper(c);
    }
    return result;
}

std::string toLowerCase(const std::string &str)
{
    std::string result;
    for (char c : str)
    {
        result += std::tolower(c);
    }
    return result;
}

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

void clearConsole()
{
    std::cout << "\033[2J\033[1;1H";
}