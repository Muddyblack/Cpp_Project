#define BOOST_TEST_MODULE ExtractorTests
#include <boost/test/unit_test.hpp>
#include "Extractor.h"

BOOST_AUTO_TEST_SUITE(ExtractorTestSuite)

    BOOST_AUTO_TEST_CASE(parseJsonStringTest)
    {
        //Given Input
        const std::string givenstring = R"(
            {
                "firstkey":"firstpair",
                "secondtkey":"secondpair",
                "thirdkey":"thirdpair"
            }
        )";
        //Expected Output
        const std::map<std::string, std::string> expected = {
                {"firstkey", "firstpair"},
                {"secondtkey", "secondpair"},
                {"thirdkey", "thirdpair"}
        };
        //Using function
        std::map<std::string, std::string> result = parseJsonString(givenstring);
        BOOST_CHECK(expected == result);
    }
/*
    BOOST_AUTO_TEST_CASE(extractOptionsAndVariablesTest)
    {

        extractOptionsAndVariables();
    }
*/
BOOST_AUTO_TEST_SUITE_END()
