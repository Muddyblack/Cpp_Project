/**
 * @file Logger.h
 * @brief Contains functions for initializing the logger.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <boost/log/trivial.hpp>
#include <string>

/**
 * @brief Sets up the logger with the specified log file path.
 *
 * This function initializes the logger and configures it to write log messages to both a file and the console.
 * The log messages with severity level equal to or higher than `info` will be logged.
 *
 * @param logFilePath The path where the log file should be saved.
 */
void setup_logging(const std::string &logFilePath);

#endif // LOGGER_H