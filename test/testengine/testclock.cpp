#include <gtest/gtest.h>

#include <chrono>
#include <thread>

#include "../../engine/src/clock.hpp"

using GampyCPP::Clock;

TEST(Clock, Initialize)
{
    ASSERT_FALSE(!glfwInit());
    Clock clock;
    EXPECT_TRUE(clock.initialize());
    EXPECT_TRUE(clock.shutdown());
}

TEST(Clock, FrameTimeMeasuring)
{
    Clock clock;
    EXPECT_TRUE(clock.initialize());
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    clock.newFrame();
    float timedTime = clock.timeElapsedLastFrame();
    EXPECT_GT(timedTime, 0.99f);
    EXPECT_LT(timedTime, 1.01f);

    clock.newFrame();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    clock.newFrame();
    timedTime = clock.timeElapsedLastFrame();
    EXPECT_GT(timedTime, 0.49f);
    EXPECT_LT(timedTime, 0.51f);

    EXPECT_TRUE(clock.shutdown());
}
