cmake_minimum_required(VERSION 3.0)
project(concurrency)

add_executable(demo1 demo1.cpp)
target_link_libraries(demo1 -lpthread)

add_executable(demo2 demo2.cpp)
target_link_libraries(demo2 -lpthread)