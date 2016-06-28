#include <gtest/gtest.h>

#include <ctime>
#include <chrono>
#include <thread>
#include <random>
#include <iostream>

#include <GampyCPP/Clock>

std::mt19937 randomEngine(time(NULL));
std::uniform_int_distribution<int> randomTestNrGenerator(10, 200);
std::uniform_int_distribution<int> randomTestsGenerator(0, 10000);

using std::cout;
using std::endl;
using std::flush;
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
    double timedTime = clock.dtLastFrame();
    EXPECT_GT(timedTime, 0.99f);
    EXPECT_LT(timedTime, 1.01f);

    clock.newFrame();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    clock.newFrame();
    timedTime = clock.dtLastFrame();
    EXPECT_GT(timedTime, 0.49f);
    EXPECT_LT(timedTime, 0.51f);

    const int NR_TESTS = randomTestNrGenerator(randomEngine);
    const float THRESHOLD = 0.001f;

    cout << "Running " << NR_TESTS << " timing tests." << endl;
    for (int i = 0; i < NR_TESTS; i++) {
        cout << "." << flush;
        int sleepTimeMillisecs = randomTestsGenerator(randomEngine);
        float sleepTimeSecs = sleepTimeMillisecs / 1000.0f;

        clock.newFrame();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTimeMillisecs));
        clock.newFrame();

        timedTime = clock.dtLastFrame();

        EXPECT_GT(timedTime, sleepTimeSecs - THRESHOLD);
        EXPECT_LT(timedTime, sleepTimeSecs + THRESHOLD);
    }
    cout << endl;

    EXPECT_TRUE(clock.shutdown());
}
