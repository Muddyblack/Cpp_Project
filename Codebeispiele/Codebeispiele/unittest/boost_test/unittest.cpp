//g++ -o unittest unittest.cpp -lboost_unit_test_framework
#define BOOST_TEST_MODULE BoostTestDemonstrator
#include <boost/test/included/unit_test.hpp>

bool isNotZero(const int value) {
    return value;
}

BOOST_AUTO_TEST_CASE( NotZeroTestCase )
{
    BOOST_TEST(isNotZero(-1) == true);
    BOOST_TEST(isNotZero(1) == true);
    BOOST_TEST(isNotZero(0) == false);
}

