#include <boost/log/core.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/support/date_time.hpp>
#include <iostream>
#include <Logger.h>

namespace logging = boost::log;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;
namespace sinks = boost::log::sinks;

void setup_logging(const std::string &logFilePath)
{
    logging::add_file_log(
        logFilePath,
        logging::keywords::filter = expr::attr<logging::trivial::severity_level>("Severity") >= logging::trivial::info,
        logging::keywords::format = "[%TimeStamp(format=\"%Y-%m-%d %H:%M:%S\")%] [%Severity%] %Message%",
        logging::keywords::auto_flush = true);

    // Create a console sink
    logging::add_console_log(
        std::cout,
        logging::keywords::filter = expr::attr<logging::trivial::severity_level>("Severity") >= logging::trivial::info && expr::attr<logging::trivial::severity_level>("Severity") < logging::trivial::debug,
        logging::keywords::format = "%Message%",
        logging::keywords::auto_flush = true);

    logging::core::get()->add_global_attribute("TimeStamp", attrs::local_clock());
}
