cmake_minimum_required(VERSION 3.9)

## Require C++11 with no extensions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

## Add Build Targets
add_subdirectory(two)
add_subdirectory(three)
add_subdirectory(six)
add_subdirectory(demo)

## Dev tools
include(cmake/clang-format.cmake)
