//
// Created by marco on 08/06/16.
//

#ifndef AMSMAZE_UTIL_H
#define AMSMAZE_UTIL_H

struct Camera
{
    GLfloat x = 0.0f;
    GLfloat y = 0.0f;
    GLfloat z = 0.0f;
    GLfloat ay = 0.0f;
    GLfloat ax = 0.0f;
};

struct Posizione
{
    GLuint prev_x = 0;
    GLuint prev_z = 0;
    GLuint cur_x = 0;
    GLuint cur_z = 0;
};

#endif //AMSMAZE_UTIL_H
