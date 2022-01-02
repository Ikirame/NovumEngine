/**
 *  @file    FlatQueueTests.cpp
 *  @author  Valentin Gerard (Ikirame)
 *  @date    12/27/2021
 *  @version 1.0
 */

#include <catch2/catch.hpp>

#include "utility/FlatQueue.hpp"

TEST_CASE("An initialized flat queue should be empty", "[FlatQueue]")
{
    // Arrange & Act
    novum_engine::utility::FlatQueue<int> queue;

    // Assert
    REQUIRE(queue.empty());
}