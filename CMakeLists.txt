cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

PROJECT(GampyCPP)

enable_testing()

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

SET(FULLTEST OFF)

ADD_SUBDIRECTORY(games)
ADD_SUBDIRECTORY(engine)
ADD_SUBDIRECTORY(test)
