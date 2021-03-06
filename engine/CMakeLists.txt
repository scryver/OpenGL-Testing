# Set version information
set(GAMPY_CPP_VERSION_MAJOR 1)
set(GAMPY_CPP_VERSION_MINOR 0)

#Create config.h
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/config.h"
)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)

FILE(GLOB ENGINE_SRCS src/*.cpp)

ADD_LIBRARY(gcEngine ${ENGINE_SRCS})

TARGET_INCLUDE_DIRECTORIES(gcEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include PUBLIC ${OPENGL_INCLUDE_DIRS} PUBLIC ${GLM_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(gcEngine ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES})

INSTALL(TARGETS gcEngine DESTINATION lib)
INSTALL(FILES src/All.hpp DESTINATION include/GampyCPP)
