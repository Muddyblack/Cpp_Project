#include <ProjectPathFinder.h>
#include <boost/log/trivial.hpp>
#include <iostream>
#include <string>
#include <filesystem>

#include <Logger.h>

namespace fs = std::filesystem;

ProjectPathFinder::ProjectPathFinder()
{
}

std::string ProjectPathFinder::getExecutablePath()
{
    const fs::path path = fs::current_path();

    return path.string();
}

std::string ProjectPathFinder::getProjectFolderPath(const std::string &PROJECT_NAME, const bool useFile)
{
    std::string executablePath;

    if (useFile)
    {
        // __FILE__ gives the complete Path to the current File during the Compilation time
        const fs::path filePath(__FILE__);
        executablePath = filePath.parent_path().string();
    }
    else
    {
        // Open Function getExecutablePath()
        executablePath = getExecutablePath();
    }

    BOOST_LOG_TRIVIAL(trace) << "executablePath: " << executablePath << std::endl;

    // If executablePath is not empty
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
        // If directory to folder is empty or if executableDir and previousDir have the same value
        if (executableDir.empty() || executableDir == previousDir)
        {
            BOOST_LOG_TRIVIAL(warning) << "Project folder not found." << std::endl;
            return executablePath;
        }

        const fs::path projectFolderPath = executableDir / PROJECT_NAME;

        if (fs::exists(projectFolderPath))
        {
            return projectFolderPath.string();
        }
    }

    // If the folder doesn't exist
    BOOST_LOG_TRIVIAL(warning) << "Project folder not found." << std::endl;
    return executablePath;
}
