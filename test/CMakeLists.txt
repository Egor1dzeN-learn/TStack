cmake_minimum_required(VERSION 3.24)
project(untitled2)

add_executable(main main.cpp test.cpp)
include_directories(../src)
target_link_libraries(main TStack)
target_link_libraries(main gtest_main gmock_main)