#define BOOST_TEST_MODULE Helperfunctionsstests
#include <boost/test/unit_test.hpp>
#include <Helperfunctions.h>
BOOST_AUTO_TEST_SUITE(Helperfunctiontestsuite)
BOOST_AUTO_TEST_CASE(toLowerCaseTest)
{
    //Input
    std::string input = "This IS a Test";
    //Expected Output
    std::string expected = "this is a test";
    //Testing
    std::string result = toLowerCase(input);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(toUpperCaseTest)
{
    //Input
    std::string input = "This IS a Test";
    //Expected Output
    std::string expected = "THIS IS A TEST";
    //Testing
    std::string result = toUpperCase(input);
    BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(checkPathTest)
{
    //Input
    std::string input = "/here/there/file";
    //Expected Output
    std::string expected = "C:\\\\here\\\\there\\\\file";
    //Testing
    std::string result = checkPath(input);
    BOOST_CHECK(result == expected);
}
    BOOST_AUTO_TEST_CASE(checkPathTestfailure)
    {
        //Input
        std::string input = "./here/there/file";
        //Expected Output
        std::string expected = "C:\\\\here\\\\there\\\\file";
        //Testing
        std::string result = checkPath(input);
        BOOST_CHECK(result != expected);
    }

BOOST_AUTO_TEST_SUITE_END()
