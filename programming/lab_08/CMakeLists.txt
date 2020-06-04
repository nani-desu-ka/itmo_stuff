cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(lab_08)
add_executable(lab_08 src/main.cpp include/Cube.hpp include/Element.hpp include/Point.hpp include/Enums.hpp src/Сube.cpp include/Color_c.hpp src/Element.cpp include/display.hpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include)
target_link_libraries(lab_08 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )