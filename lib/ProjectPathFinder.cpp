#include <ProjectPathFinder.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

std::string GetExecutablePath()
{
    fs::path path = fs::current_path();
    return path.string();
}

ProjectPathFinder::ProjectPathFinder(const std::string &projectName)
    : PROJECT_NAME(projectName)
{
}

std::string ProjectPathFinder::GetProjectFolderPath()
{
    std::string executablePath = GetExecutablePath();
    if (!executablePath.empty())
    {
        fs::path executableDir = fs::path(executablePath).parent_path();
        fs::path previousDir;

        // Go up the directory path until PROJECT_NAME is found
        while (!executableDir.empty() && executableDir != previousDir && !fs::exists(executableDir / PROJECT_NAME))
        {
            previousDir = executableDir;
            executableDir = executableDir.parent_path();
        }

        if (executableDir.empty() || executableDir == previousDir)
        {
            std::cout << "Project folder not found." << std::endl;
            return executablePath;
        }

        fs::path projectFolderPath = executableDir / PROJECT_NAME;

        if (fs::exists(projectFolderPath))
        {
            return projectFolderPath.string();
        }
    }

    std::cout << "Project folder not found." << std::endl;
    return executablePath;
}
