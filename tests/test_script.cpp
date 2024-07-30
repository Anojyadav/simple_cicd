#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>// Include the Catch2 header

// Include the header file for the function you want to test
#include "sum.h"

// Define a test case
TEST_CASE("Sum function test", "[sum]") {
    REQUIRE(add_num(2, 4) == 5);   // Test for sum of 2 and 3
    REQUIRE(add_num(-1, 1) == 0);  // Test for sum of -1 and 1
    REQUIRE(add_num(-2, -3) == -5); // Test for sum of -2 and -3
}