cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(lab_07)
add_executable(lab_07 src/main.cpp include/Cube.h src/Corner_element.cpp include/Interfaces.hpp include/Point.hpp include/Enums.hpp include/Corner_element.hpp include/Center_element.hpp include/Edge_element.hpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include)
target_link_libraries(lab_07 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
