cmake_minimum_required(VERSION 3.3)
project(FEI)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp classes/Function.h classes/Function.cpp)
add_executable(FEI ${SOURCE_FILES})