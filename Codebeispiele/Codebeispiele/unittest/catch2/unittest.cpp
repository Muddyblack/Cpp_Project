#define CATCH_CONFIG_FAST_COMPILE
#include <catch.hpp>

bool isNotZero(const int value) {
    return value;
}

TEST_CASE("Catch2Demonstrator")
{
    SECTION("NotZeroTestCase")
    {
        CHECK(isNotZero(-1) == true);
        CHECK(isNotZero(1) == true);
        CHECK(isNotZero(0) == false);
    }
}

