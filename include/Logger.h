#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include <boost/log/trivial.hpp>

void setup_logging(const std::string &logFilePath);

#endif // LOGGER_HPP