//
// Created by marco on 08/06/16.
//

#ifndef AMSMAZE_UTIL_H
#define AMSMAZE_UTIL_H

static const GLchar *titolo = "AMSMaze";
static const GLchar *fileInput = "res/input_maze.txt";
static const GLchar *fileOutput = "res/output_maze.txt";
static const int windowWidth = 600;
static const int windowHeight = 600;
static const int windowPosX = 100;
static const int windowPosY = 100;

static const int tempoGioco = 20 * 1000;
static bool startGioco = false;
static bool tempoFinito = false;
static int secondiAlTermine = 0;
static int tempoTrascorso = 0;
static int tempoInizio = 0;

static const GLfloat pi_180 = 180.0f / 3.141592f;
static const GLfloat dimCubo = 0.5f;
static const GLfloat dimCamera = 0.07f;
static const GLfloat spostamento = 0.25f;
static const GLfloat angolo = 2.5f;
static const GLint heightMaze = 15;
static const GLint widthMaze = 15;

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

struct Coppia
{

};

#endif //AMSMAZE_UTIL_H
