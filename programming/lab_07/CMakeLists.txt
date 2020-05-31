cmake_minimum_required(VERSION 3.15)
project(lab_7)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(lab_07 src/main.cpp src/console_handler.cpp
        include/console_handler.h include/circular_buffer.hpp src/exception.cpp include/exception.hpp)