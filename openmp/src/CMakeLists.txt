#Requied CMake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

#We need to add to how to find TBB which sits in the cmake dir
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


#Name of our cmake project
project(openMP LANGUAGES CXX)

#Require c++111
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(OpenMP REQUIRED)
find_package(TBB REQUIRED)



#Make sure we can find the giee libraries
find_package(genericIO REQUIRED)
include_directories(${GENERICIO_INCLUDE_DIR})
link_directories(${GENERICIO_LIB_DIR})

MESSAGE(${GENERICIO_LIB_DIR} "LINK DIR")
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)




#include the giee directories when compiling and linking
include_directories(${genericIO_DIRNAME_include})
LINK_DIRECTORIES(${genericIO_DIRNAME_lib})

LINK_DIRECTORIES(/opt/SEP/lib)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")

#we also need boost 
FIND_PACKAGE( Boost 1.40 COMPONENTS program_options unit_test_framework REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

#add the rules for building the C++ code
add_subdirectory(lib)

#add the rules for python binding
add_subdirectory(python)

