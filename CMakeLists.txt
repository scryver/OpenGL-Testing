cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

PROJECT(GampyCPP)

enable_testing()

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

ADD_SUBDIRECTORY(games)
ADD_SUBDIRECTORY(engine)
ADD_SUBDIRECTORY(test)

# set(CMAKE_CXX_STANDARD 11)

# project(GLFWGame)

# # Set version information
# set(GLFW_GAME_VERSION_MAJOR 1)
# set(GLFW_GAME_VERSION_MINOR 0)

# #Create config.h
# configure_file(
#     "${PROJECT_SOURCE_DIR}/src/config.h.in"
#     "${PROJECT_BINARY_DIR}/config.h"
# )

# find_package(OpenGL REQUIRED)
# find_package(GLEW REQUIRED)
# find_package(GLFW REQUIRED)

# set(EXECUTABLE_NAME "GLFWGame")
# add_executable(${EXECUTABLE_NAME}
#     src/main.cpp
#     src/renderelement.cpp
#     src/shader.cpp
#     src/window.cpp
# )


# include_directories("${PROJECT_BINARY_DIR}" ${OPENGL_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
# target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES})


# install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# include(InstallRequiredSystemLibraries)
# # set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
# set(CPACK_PACKAGE_VERSION_MAJOR "${SFML_GAME_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${SFML_GAME_VERSION_MINOR}")
# include(CPack)


