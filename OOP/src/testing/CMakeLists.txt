cmake_minimum_required(VERSION 3.1)
project(buffers-utest)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../external/googletest/googletest/include")


 set(GTEST ../external/googletest/googlemock/gtest/libgtest.a  ../external/googletest/googlemock/gtest/libgtest_main.a  ../external/googletest/googlemock/gtest/libgtest.a )

add_executable( vectorTest vectorTest.cc)
target_link_libraries(vectorTest  OOPLab gtest gtest_main gtest )
add_test(AllstlVectorTests vectorTest)


