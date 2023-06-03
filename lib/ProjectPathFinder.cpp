#include "ProjectPathFinder.h"

#ifdef _WIN32
#include <windows.h>

/**
 * @brief Retrieves the path of the current executable on Windows.
 * @return The path of the current executable.
 */
std::string GetExecutablePath()
{
    TCHAR buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    return std::string(buffer);
}

#elif __APPLE__
#include <mach-o/dyld.h>

/**
 * @brief Retrieves the path of the current executable on macOS.
 * @return The path of the current executable.
 */
std::string GetExecutablePath()
{
    char buffer[PATH_MAX];
    uint32_t size = sizeof(buffer);
    if (_NSGetExecutablePath(buffer, &size) == 0)
        return std::string(buffer);
    else
        return "";
}

#elif __unix__
#include <unistd.h>

/**
 * @brief Retrieves the path of the current executable on Unix-like systems.
 * @return The path of the current executable.
 */
std::string GetExecutablePath()
{
    char buffer[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
    if (len != -1)
    {
        buffer[len] = '\0';
        return std::string(buffer);
    }
    else
        return "";
}

#else
#error Unsupported platform

#endif

/**
 * @brief Constructs a ProjectPathFinder object with the specified project name.
 * @param projectName The name of the project.
 */
ProjectPathFinder::ProjectPathFinder(const std::string &projectName)
    : PROJECT_NAME(projectName)
{
}

/**
 * @brief Retrieves the project folder path.
 * @return The project folder path.
 */
std::string ProjectPathFinder::GetProjectFolderPath()
{
    std::string executablePath = GetExecutablePath();
    if (!executablePath.empty())
    {
        size_t projectNamePos = executablePath.find(PROJECT_NAME);
        if (projectNamePos == std::string::npos)
        {
            std::cout << "Project name not found." << std::endl;
            return "";
        }

        std::string projectFolderPath = executablePath.substr(0, projectNamePos + PROJECT_NAME.length() + 1);
        return projectFolderPath;
    }

    return "";
}
