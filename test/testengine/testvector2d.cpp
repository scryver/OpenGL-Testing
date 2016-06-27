#include <gtest/gtest.h>

#include "../../engine/src/math/vector2d.hpp"

using GampyCPP::Math::Vector2D;

TEST(Vector2D, Constructor)
{
    Vector2D vector(1, 2);
    EXPECT_FLOAT_EQ(1.0f, vector.x);
    EXPECT_FLOAT_EQ(2.0f, vector.y);
}

TEST(Vector2D, VectorAddition)
{
    Vector2D first(1, 2);
    Vector2D second(3, 4);

    Vector2D result1 = first + second;
    Vector2D result2 = second + first;

    EXPECT_FLOAT_EQ(result1.x, 4);
    EXPECT_FLOAT_EQ(result1.y, 6);

    EXPECT_FLOAT_EQ(result1.x, result2.x);
    EXPECT_FLOAT_EQ(result1.y, result2.y);
}

TEST(Vector2D, ScalarMultiplication)
{
    Vector2D vector(1, 2);
    float scalar = 2.0f;

    Vector2D result1 = scalar * vector;
    Vector2D result2 = vector * scalar;

    EXPECT_FLOAT_EQ(result1.x, 2);
    EXPECT_FLOAT_EQ(result1.y, 4);

    EXPECT_FLOAT_EQ(result1.x, result2.x);
    EXPECT_FLOAT_EQ(result1.y, result2.y);

    Vector2D vector2(-12, 3.5);

    Vector2D result3 = 9 * vector2;
    Vector2D result4 = vector2 * 9;

    EXPECT_FLOAT_EQ(result3.x, -108);
    EXPECT_FLOAT_EQ(result3.y, 31.5f);

    EXPECT_FLOAT_EQ(result3.x, result4.x);
    EXPECT_FLOAT_EQ(result3.y, result4.y);
}
