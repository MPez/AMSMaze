//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_GAME_H
#define PROGETTO_GAME_H


#include "Maze.h"

class Game {
private:
    const GLchar *titolo = "AMSMaze";
    const char *fileInput = "res/input_maze.txt";
    const GLfloat pi_180 = 180.0f / 3.141592f;
    const GLfloat dimCubo = 0.5f;
    const GLfloat dimCamera = 0.125f;
    const GLfloat spostamento = 0.125f;
    const GLfloat angolo = 2.5f;

    Maze maze;

public:

    Game();

    const GLchar *getTitolo() const {
        return titolo;
    }

    const char *getFileInput() const {
        return fileInput;
    }

    const GLfloat getPi_180() const {
        return pi_180;
    }

    const GLfloat getDimCubo() const {
        return dimCubo;
    }

    const GLfloat getDimCamera() const {
        return dimCamera;
    }

    const GLfloat getSpostamento() const {
        return spostamento;
    }

    const GLfloat getAngolo() const {
        return angolo;
    }
};


#endif //PROGETTO_GAME_H
