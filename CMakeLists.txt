cmake_minimum_required(VERSION 3.5)
project(hello VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(hello main.cpp)
add_executable(tests testing.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
