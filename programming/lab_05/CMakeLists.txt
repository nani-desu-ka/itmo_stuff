cmake_minimum_required(VERSION 3.15)
project(lab_05)
set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(lab_05 src/main.cpp include/array_handler.tpp src/console_handler.cpp
        include/custom_stack.h include/custom_stack.tpp)