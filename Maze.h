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
    GLfloat pos_r;
    GLfloat pos_c;
    GLfloat end_r;
    GLfloat end_c;
    std::vector<std::vector<GLuint>> maze;
    Camera &camera;

public:
    Maze(Camera &camera);
    ~Maze();

    void disegnaMaze(GLfloat dim);

    void disegnaPorte(GLfloat dim);

    void disegnaPavimento(GLfloat dim);

    void disegnaSoffitto(GLfloat dim);

    void disegnaLineePavimento();

    void disegnaLuci();

    void eseguiSpostamento(GLfloat x, GLfloat z);

    void parseInput(const char *file);

    void setStart();

    bool isExit(int i, int j);

    bool isEntrance(int i, int j);
};

#endif //PROGETTO_MAZE_H
