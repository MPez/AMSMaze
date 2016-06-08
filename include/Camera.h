//
// Created by marco on 08/06/16.
//

#ifndef AMSMAZE_CAMERA_H
#define AMSMAZE_CAMERA_H


#include <GL/glut.h>

class Camera {
public:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat ay;
    GLfloat ax;

    Camera();
};


#endif //AMSMAZE_CAMERA_H
