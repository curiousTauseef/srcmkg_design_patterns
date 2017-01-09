# Declare the minimum version of cmake that we need
cmake_minimum_required(VERSION 2.6)

set(sources
   adapterExternalPolymorphism.cpp
   main.cpp)

# Build the executable
add_executable(adapterEP ${sources})
