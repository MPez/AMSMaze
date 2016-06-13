//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_MAZE_H
#define PROGETTO_MAZE_H

#include <GL/glut.h>
#include <vector>
#include <string>
#include "Util.h"
#include "Cubo.h"

class Maze {
private:
    GLuint row;
    GLuint col;
    GLfloat start_r;
    GLfloat start_c;
    std::vector<std::vector<GLuint>> maze;
    Camera camera;

public:
    Maze();
    ~Maze();

    void generaMaze();

    void stampaMaze();

    void disegnaMaze(GLfloat dim);

    void disegnaPavimento(GLfloat dim);

    void disegnaSoffitto(GLfloat dim);

    void disegnaLineePavimento();

    void disegnaLuci();

    void eseguiSpostamento(GLfloat x, GLfloat z, Camera &camera);

    void parseInput(const char *file);

    GLfloat getStart_r() const {
        return start_r;
    }

    GLfloat getStart_c() const {
        return start_c;
    }
};

#endif //PROGETTO_MAZE_H
