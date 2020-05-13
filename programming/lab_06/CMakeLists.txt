cmake_minimum_required(VERSION 3.15)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(lab_06 src/main.cpp src/console_handler.cpp
        src/algorithms.tpp src/custom_class.cpp include/console_handler.h
        include/algorithms.hpp include/custom_class.hpp)