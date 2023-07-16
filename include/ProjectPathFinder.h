/**
 * @file ProjectPathFinder.h
 * @brief Contains functions and classes for retrieving the project path.
 */

#ifndef PROJECTPATHFINDER_H
#define PROJECTPATHFINDER_H

#include <string>

/**
 * @class ProjectPathFinder
 * @brief A class that helps in finding the project folder path.
 *
 * The ProjectPathFinder class provides functions to retrieve the path of the current executable and the project folder path.
 * It can be used to determine the location of the project folder based on the current source file or the current executable.
 */
class ProjectPathFinder
{
public:
    /**
     * @brief Constructs a ProjectPathFinder object with the specified project name.
     *
     * @param projectName The name of the project.
     */
    explicit ProjectPathFinder();

    /**
     * @brief Retrieves the path of the current executable.
     *
     * @return The path of the current executable.
     */
    std::string getExecutablePath();

    /**
     * @brief Retrieves the project folder path.
     *
     * @param PROJECT_NAME The name of the project.
     * @param useFile If true, the function uses the file path of the current source file to determine the location of the project folder.
     *                If false, the function uses the path of the current executable.
     *
     * @return The project folder path.
     */
    std::string getProjectFolderPath(std::string &PROJECT_NAME, bool useFile = true);

private:
    std::string PROJECT_NAME; /**< The name of the project. */
};
#endif // PROJECTPATHFINDER_H