#Tell Cmake to look in the current directory for our source files
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#List the sources and includes for our awesome library
set(SOURCES dow30.cc)
set(INCLUDES dow30.h)

add_library(dowJones ${SOURCES} ${INCLUDES})