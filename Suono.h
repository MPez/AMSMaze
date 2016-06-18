//
// Created by marco on 18/06/16.
//

#ifndef AMSMAZE_SUONO_H
#define AMSMAZE_SUONO_H


#include <AL/alut.h>
#include <GL/glut.h>
#include "Util.h"
#include "Maze.h"

class Suono {
private:
    ALfloat listenerOrientation[6];
    ALuint militaryBuffer, militarySource;
    ALuint alarmBuffer, alarmSource;
    Camera &camera;
    Maze &maze;

public:
    Suono(Camera &camera, Maze &maze);
    ~Suono();

    void impostaSuoni();

    void spegniSuono(int suono);
};


#endif //AMSMAZE_SUONO_H
