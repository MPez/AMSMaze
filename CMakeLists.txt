cmake_minimum_required(VERSION 3.5)
project(AMSMaze)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGL -lGLU -lglut")

include_directories(include)

set(SOURCE_FILES
        Cubo.cpp
        Game.cpp
        AMSmaze.cpp
        Maze.cpp
        ResourceManager.cpp
        Camera.cpp)

add_executable(AMSMaze ${SOURCE_FILES})