#define BOOST_TEST_MODULE ProjectPathFinderTests
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>
#include "ProjectPathFinder.h"

BOOST_AUTO_TEST_SUITE(ProjectPathFinderTestSuite)

BOOST_AUTO_TEST_CASE(GetExecutablePathTest)
{
    std::string projectName = "GenTxtSrcCode";
    ProjectPathFinder pathFinder(projectName);
    std::string executablePath = pathFinder.GetExecutablePath();
    BOOST_CHECK(!executablePath.empty());
    BOOST_CHECK(boost::filesystem::exists(executablePath));
}

BOOST_AUTO_TEST_CASE(GetProjectFolderPathTest)
{
    std::string projectName = "GenTxtSrcCode";
    ProjectPathFinder pathFinder(projectName);

    std::string projectFolderPath = pathFinder.GetProjectFolderPath();
    BOOST_CHECK(!projectFolderPath.empty());
    BOOST_CHECK(boost::filesystem::exists(projectFolderPath));
    BOOST_CHECK(boost::filesystem::is_directory(projectFolderPath));
    BOOST_CHECK(projectFolderPath.find(projectName) != std::string::npos);
}

BOOST_AUTO_TEST_SUITE_END()
