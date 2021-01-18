cmake_minimum_required(VERSION 3.15)
project(lab_13 C)

set(CMAKE_C_STANDARD 99)

include_directories(BMP_library)

add_executable(lab_13 main.c bmp_library.h bmp_library.c)