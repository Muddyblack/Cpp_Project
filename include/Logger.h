/**
 * @file Logger.h
 * @brief Initializes the logger
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <boost/log/trivial.hpp>
#include <string>

/**
 * Setting up the logger
 *
 * @param logFilePath The input string containing the path where the log should be saved
 */
void setup_logging(const std::string &logFilePath);

#endif // LOGGER_H