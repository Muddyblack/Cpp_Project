#include "ProjectPathFinder.h"
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
        fs::path projectFolderPath = executableDir / PROJECT_NAME;
        if (fs::exists(projectFolderPath))
        {
            return projectFolderPath.string();
        }
        else
        {
            std::cout << "Project folder not found." << std::endl;
            return "";
        }
    }

    return "";
}