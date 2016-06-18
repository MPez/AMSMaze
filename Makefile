CC=g++
CPPFLAGS=-lGL -lGLU -lglut -lalut -lopenal

SOURCES=main.cpp Cubo.cpp Maze.cpp ResourceManager.cpp Suono.cpp
EXECUTABLE=AMSmaze

all:
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CPPFLAGS)

.PHONY: clean
clean:
	rm AMSmaze

