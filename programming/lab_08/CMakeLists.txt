cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(lab_07)
add_executable(lab_07 src/main.cpp include/cube.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include)
target_link_libraries(lab_07 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
