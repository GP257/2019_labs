

#TELL CMAKE TO LOOK IN THE CURRENT DIRECTORY FOR OUR SOURCE FILES
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#LIST THE SOURCES AND INCLUDES FOR OUR  AWESOME LIBRARY
set(SOURCES 	wavelet2D.cc mult.cc	)
set(INCLUDES  wavelet2D.h mult.h)

add_custom_command(OUTPUT kernel.o
                   COMMAND ispc --target=avx2-i32x8 ${CMAKE_CURRENT_SOURCE_DIR}/kernel.ispc -o kernel.o
                   DEPENDS kernel.ispc)

add_library(ISPCLab kernel.o ${SOURCES} ${INCLUDES})
