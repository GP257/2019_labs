#TELL WHAT VERSION OF CMAKE WE REQUIRE
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#Name our project and language we are going to use
project(example LANGUAGES CXX)

#We want to require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#Here is the executable we want to build
add_executable(prop.x prop.cc main.cc field3d.cc timer.cc)
