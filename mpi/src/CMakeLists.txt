#TELL WHAT VERSION OF CMAKE WE REQUIRE
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

#Name our project and language we are going to use
project(mpi-test LANGUAGES C)


find_package(MPI REQUIRED)

#Here is the executable we want to build
add_executable(pingPong pingpong.c)

target_include_directories(pingPong PRIVATE ${MPI_C_INCLUDE_PATH} )
target_compile_options(pingPong PRIVATE ${MPI_C_COMPILE_FLAGS} -O3 )
target_link_libraries(pingPong ${MPI_C_LIBRARIES} ${MPI_C_LINK_FLAGS} )
