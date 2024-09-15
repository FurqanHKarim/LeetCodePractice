cmake_minimum_required(VERSION 3.15)
project(testing_env)

# Follwoing will include the files that need to be included ie. hpp files for this project
include_directories(${PROJECT_SOURCE_DIR}/inc/)

# This will creat the main executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/app/main.cpp)


# Following only stores the paths of all the cpp files in keyname sources
file(GLOB sources 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# This will create a sinlge object file of the cpp files in sources
add_library(all_lib STATIC ${sources})

# this wil link the object files created from sources to the main executable
target_link_libraries(${PROJECT_NAME} PUBLIC all_lib)


# I just like this build system
set (CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
