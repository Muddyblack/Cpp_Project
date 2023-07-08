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
    fs::path path = fs::current_path();

    return path.string();
}

std::string ProjectPathFinder::getProjectFolderPath(std::string &PROJECT_NAME, bool useFile)
{
    std::string executablePath;

    if (useFile)
    {
        fs::path filePath(__FILE__);
        executablePath = filePath.parent_path().string();
    }
    else
    {
        executablePath = getExecutablePath();
    }

    BOOST_LOG_TRIVIAL(trace) << "executablePath: " << executablePath << std::endl;

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
            BOOST_LOG_TRIVIAL(warning) << "Project folder not found." << std::endl;
            return executablePath;
        }

        fs::path projectFolderPath = executableDir / PROJECT_NAME;

        if (fs::exists(projectFolderPath))
        {
            return projectFolderPath.string();
        }
    }

    BOOST_LOG_TRIVIAL(warning) << "Project folder not found." << std::endl;
    return executablePath;
}
