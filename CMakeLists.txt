cmake_minimum_required(VERSION 3.5)
project(AMSMaze)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lGL -lGLU -lglut")

set(SOURCE_FILES
        Cubo.cpp
        Cubo.h
        main.cpp
        Maze.cpp
        Maze.h
        ResourceManager.cpp
        ResourceManager.h
        Util.h Timer.cpp Timer.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})