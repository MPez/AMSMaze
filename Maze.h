//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_MAZE_H
#define PROGETTO_MAZE_H

#include <GL/glut.h>
#include <vector>

class Maze {
private:
    GLuint row;
    GLuint col;
    GLuint start_r;
    GLuint start_c;
    std::vector<std::vector<GLuint>> maze;

public:
    Maze();
    ~Maze();

    void parseInput(std::string file);


    GLuint getRow() const;

    GLuint getCol() const;

    GLuint getStart_r() const;

    GLuint getStart_c() const;
};

#endif //PROGETTO_MAZE_H
