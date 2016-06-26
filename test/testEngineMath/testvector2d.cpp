#include <gtest/gtest.h>

#include "../../engine/src/All.hpp"

using GampyCPP::Math::Vector2D;

TEST(Vector2D, Constructor)
{
    Vector2D vector(1, 2);
    EXPECT_EQ(1, vector.x);
    EXPECT_EQ(2, vector.y);
}

TEST(Vector2D, VectorAddition)
{
    Vector2D first(1, 2);
}

TEST(Vector2D, ScalarMultiplication)
{

}
