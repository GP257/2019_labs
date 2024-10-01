#Specify what version of Cmake we require
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#Name the project and specify what programming language we use
project(example LANGUAGES CXX)

#Specify that we require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Add subdirectory in which there are more rules for building things
add_subdirectory(lib)

#We need to tell it to look in the library directory for .h files
include_directories(lib)

#Here is the executable we want to build
add_executable(dowGame dowGame.cc)

#Our executable needs this library
target_link_libraries(dowGame dowJones)