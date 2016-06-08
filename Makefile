SHELL=/bin/bash

CC=g++

OBJECTS=AMSmaze.o Camera.o Cubo.o Game.o Maze.o ResourceManager.o
SRCS=AMSmaze.cpp Camera.cpp Cubo.cpp Game.cpp Maze.cpp ResourceManager.cpp

AMSmaze: $(OBJECTS)
	$(CC) -o $@ $<

AMSmaze.o: $(SRCS)
	$(CC) -c -o $@ $<
	
clean:
	rm -f *.o
	
.PHONY: clean
