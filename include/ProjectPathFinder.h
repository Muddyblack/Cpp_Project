#pragma once

#include <iostream>
#include <string>

/**
 * @brief Retrieves the path of the current executable.
 * @return The path of the current executable.
 */
std::string GetExecutablePath();

/**
 * @brief A class that helps in finding the project folder path.
 */
class ProjectPathFinder
{
public:
    /**
     * @brief Constructs a ProjectPathFinder object with the specified project name.
     * @param projectName The name of the project.
     */
    ProjectPathFinder(const std::string &projectName);

    /**
     * @brief Retrieves the project folder path.
     * @return The project folder path.
     */
    std::string GetProjectFolderPath();

private:
    std::string PROJECT_NAME; /**< The name of the project. */
};
