FILE(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testEngine ${SRCS})

TARGET_LINK_LIBRARIES(testEngine
    gcEngine
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
)

# ADD_CUSTOM_COMMAND(TARGET testEngine POST_BUILD COMMAND "./testEngine")
ADD_TEST(GC_Engine testEngine)
