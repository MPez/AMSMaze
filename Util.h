//
// Created by marco on 08/06/16.
//

#ifndef AMSMAZE_UTIL_H
#define AMSMAZE_UTIL_H

static const GLchar *titolo = "AMSMaze";
static const GLchar *fileInput = "res/input_maze.txt";
static const GLfloat pi_180 = 180.0f / 3.141592f;
static const GLfloat dimCubo = 0.5f;
static const GLfloat dimCamera = 0.07f;
static const GLfloat spostamento = 0.25f;
static const GLfloat angolo = 2.5f;

struct Camera
{
    GLfloat x = 0.0f;
    GLfloat y = 0.0f;
    GLfloat z = 0.0f;
    GLfloat ay = 0.0f;
    GLfloat ax = 0.0f;
};

inline GLfloat mysign(GLfloat f)
{
    if(f > 0.0)
    {
        return 1.0f;
    }
    return (f == 0.0f) ? 0.0f : -1.0f;
}

inline int myround(GLfloat f)
{
    return (f - ceil(f) < -0.9f) ? floor(f) : ceil(f);
}

inline int myround2(GLfloat f)
{
    return (f - ceil(f) < -0.1f) ? ceil(f) : floor(f);
}

inline int myround_pos(GLfloat f)
{
    if(f >= 0.0)
    {
        return (f - floor(f) > 0.8) ? ceil(f) : floor(f);
    }
    return (f - ceil(f) < -0.8) ? floor(f) : ceil(f);
}

inline int myround_neg(GLfloat f)
{
    if(f >= 0.0)
    {
        return (f - floor(f) < 0.8) ? ceil(f) : floor(f);
    }
    return (f - ceil(f) > -0.8) ? floor(f) : ceil(f);
}

#endif //AMSMAZE_UTIL_H
