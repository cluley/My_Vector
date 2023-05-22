cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(My_Vector)
add_executable(My_Vector main.cpp, vector.h)

add_executable(My_Vector_test test.cpp, vector.h)
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(My_Vector PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)