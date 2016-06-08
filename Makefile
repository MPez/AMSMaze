CC=g++
CPPFLAGS=-lGL -lGLU -lglut

SOURCES=main.cpp Cubo.cpp Maze.cpp ResourceManager.cpp
EXECUTABLE=AMSmaze

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CPPFLAGS)

.PHONY: clean
clean:
	rm AMSmaze

