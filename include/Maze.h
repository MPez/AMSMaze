//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_MAZE_H
#define PROGETTO_MAZE_H

#include <GL/glut.h>
#include <vector>
#include <string>
#include "Camera.h"

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

    void disegnaMaze(GLfloat dim);

    void disegnaPavimento(GLfloat dim);

    void disegnaLineePavimento();

    void disegnaLuci();

    bool controllaSpostamento(GLfloat x, GLfloat z, Camera camera);

    void parseInput(const char *file);


    GLuint getStart_r() const {
        return start_r;
    }

    GLuint getStart_c() const {
        return start_c;
    }
};

#endif //PROGETTO_MAZE_H
