cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(lab_08)
add_executable(lab_08 src/main.cpp include/Board.hpp include/Element.hpp include/Point.hpp include/Enums.hpp src/Board.cpp include/Color_c.hpp src/Element.cpp include/display.hpp include/Figure.hpp src/Player.cpp include/Player.hpp src/Pawn.cpp include/Pawn.hpp src/Empty.cpp include/Empty.hpp include/Turn.hpp src/Turn.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} include)
target_link_libraries(lab_08 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )