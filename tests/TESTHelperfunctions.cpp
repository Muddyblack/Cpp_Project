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
    BOOST_CHECK(expected == toLowerCase(input));
}

BOOST_AUTO_TEST_CASE(toUpperCaseTest)
{
    //Input
    std::string input = "This IS a Test";
    //Expected Output
    std::string expected = "THIS IS A TEST";
    //Testing
    BOOST_CHECK(expected == toUpperCase(input));
}

BOOST_AUTO_TEST_CASE(checkPathTest)
{
    //Input
    std::string input = "/here/there/file";
    std::cout << "input: " << input << std::endl;
    //Expected Output
    std::string expected = "C:\\\\here\\\\there\\\\file";
    //Testing
    std::string result = checkPath(input);
    std::cout << "result: " << result << std::endl;
    BOOST_CHECK(result == expected);
}
    BOOST_AUTO_TEST_CASE(checkPathTestfailure)
    {
        //Input
        std::string input = "./here/there/file";
        std::cout << "input: " << input << std::endl;
        //Expected Output
        std::string expected = "C:\\\\here\\\\there\\\\file";
        //Testing
        std::string result = checkPath(input);
        std::cout << "result: " << result << std::endl;
        BOOST_CHECK(result != expected);
    }

BOOST_AUTO_TEST_SUITE_END()
