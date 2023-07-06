#ifndef LOGGER_H
#define LOGGER_H

#include <boost/log/trivial.hpp>
#include <string>

void setup_logging(const std::string &logFilePath);

#endif // LOGGER_H