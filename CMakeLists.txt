cmake_minimum_required(VERSION 3.20)

project(MyVector)
add_executable(MyVector main.cpp vector.h)

add_subdirectory(Catch2 Catch2-build)
add_executable(MyVectorTests test.cpp vector.h)
target_link_libraries(MyVectorTests PRIVATE Catch2::Catch2)