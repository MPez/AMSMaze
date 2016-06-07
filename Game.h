//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_GAME_H
#define PROGETTO_GAME_H


#include "Maze.h"

class Game {
private:
    static const char* TITOLO = "AMSMaze";
    static const GLfloat PI_180 = 180.0f / 3.141592f;
    static const GLfloat DIM_CUBO = 0.5f;
    static const GLfloat DIM_CAMERA = 0.125f;
    static const GLfloat SPOSTAMENTO = 0.125f;
    static const GLfloat ANGOLO = 2.5f;

    Maze maze;

public:
};


#endif //PROGETTO_GAME_H
