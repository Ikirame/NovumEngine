/**
 *  @file    DemoTests.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2021
 */

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Demo Test", "Demo")
{
    // Arrange
    constexpr int a = 5;

    // Act
    constexpr int b = a + 5;

    // Assert
    REQUIRE(b == 10);
}