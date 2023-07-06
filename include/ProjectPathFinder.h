/**
 * @file ProjectPathFinder.h
 * @brief Contains functions and classes for retrieving the project path.
 */

#ifndef PROJECTPATHFINDER_H
#define PROJECTPATHFINDER_H

#include <string>

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
    explicit ProjectPathFinder(const std::string &projectName);

    /**
     * @brief Retrieves the path of the current executable.
     * @return The path of the current executable.
     */
    std::string GetExecutablePath();

    /**
     * @brief Retrieves the project folder path.
     * @return The project folder path.
     */
    std::string GetProjectFolderPath(bool useFile = true);

private:
    std::string PROJECT_NAME; /**< The name of the project. */
};
#endif // PROJECTPATHFINDER_H