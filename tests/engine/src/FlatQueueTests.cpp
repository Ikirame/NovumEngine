/**
 *  @file    FlatQueueTests.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2021
 */

#include "catch2/catch_test_macros.hpp"

#include "utility/FlatQueue.hpp"

TEST_CASE("An initialized flat queue should be empty", "[FlatQueue]")
{
    // Arrange & Act
    const novum_engine::utility::FlatQueue<int> queue;

    // Assert
    REQUIRE(queue.empty());
}