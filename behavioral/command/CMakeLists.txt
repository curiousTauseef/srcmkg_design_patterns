# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

set(sources
   commandAfter.cpp
   main.cpp)

# Build the executable
add_executable(commandAfter ${sources})
