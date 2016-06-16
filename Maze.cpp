/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stack>
#include <stdlib.h>

#include "Maze.h"

Maze::Maze(Camera &camera) : camera(camera)
{}

Maze::~Maze() {}

void Maze::eseguiSpostamento(GLfloat x, GLfloat z)
{
    int i, j;

    /*
     * calcola gli indici della casella in cui si vuole spostare il giocatore
     */
    i = (int) abs(round(camera.z + z + dimCamera * mysign(z)));
    j = (int) abs(round(camera.x + x + dimCamera * mysign(x)));

    //printf("Controllo camera.z: %f, camera.x: %f, z: %f, x: %f, i:%i, j: %i\n",
    //       z, camera.z, x, camera.x, i, j);

    /*
     * controlla se c'è un muro o siamo di fronte alla porta di ingresso o uscita:
     * in caso negativo esegue lo spostamento
     */
    if(!maze[i][j] && !isEntrance(i, j) && !isExit(i, j))
    {
        camera.z += z;
        camera.x += x;
    }
}

void Maze::setStart()
{
    camera.x = pos_c;
    camera.z = -pos_r;
    camera.y = dimCubo;
    camera.ay = 0.0f;
}

bool Maze::isExit(int i, int j)
{
    /*
     * controlla se i parametri corrispondono alla casella di uscita dal labirinto
     */
    if(i == (int) end_r  &&
            (j == (int) end_c || j == (int) end_c + 1.0f || j == (int) end_c - 1.0f))
    {
        return true;
    }
    return false;
}

bool Maze::isEntrance(int i, int j)
{
    /*
     * controlla se i parametri corrispondono alla casella di ingresso nel labirinto
     */
    if(i == (int) start_r && j == (int) start_c)
    {
        return true;
    }
    return false;
}

void Maze::disegnaMaze(GLfloat dim)
{
    Cubo cubo(dim, 0, 0, 0);

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (maze[i][j])
            {
                cubo.setPosizione(j, dim, -i);
                cubo.disegna();
            }
        }
    }
}

void Maze::disegnaPortaStart(GLfloat dim)
{
    Cubo cubo(dim, start_c, dim, -start_r);
    cubo.disegna();
}

void Maze::disegnaPortaEnd(GLfloat dim)
{
    Cubo cubo(dim, end_c, dim, -end_r);
    cubo.disegna();
}

void Maze::disegnaPavimento(GLfloat dim)
{
    int fact = 2;
    Cubo cubo(dim * fact, dim * fact, 0.05f, 0, 0, 0);

    for (int i = 0; i <= ceil(row/fact); ++i)
    {
        for (int j = 0; j <= ceil(col/fact); ++j)
        {
            cubo.setPosizione(j * fact, -0.05f, -i * fact);
            cubo.disegna();
        }
    }
}

void Maze::disegnaSoffitto(GLfloat dim)
{
    int fact = 4;
    Cubo cubo(dim * fact, dim * fact, 0.05f, 0, 0, 0);

    for (int i = 0; i <= ceil(row/fact); ++i)
    {
        for (int j = 0; j <= ceil(col/fact); ++j)
        {
            cubo.setPosizione(j * fact, 1.05f, -i * fact);
            cubo.disegna();
        }
    }
}

void Maze::disegnaLuci()
{
    GLfloat lightPosition[] = {0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat spotDirection[] = {0.0f, -0.6f, -1.0f};

    GLfloat ambientLight[] = {1.0f, 1.0f, 0.6f, 1.0f};
    GLfloat diffuseLight[] = {1.0f, 1.0f, 0.6f, 1.0f};
    GLfloat specularLight[] = {0.5f, 0.6f, 0.6f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);
    //glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.2f);
    //glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.6f);

    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 5.0);

    glEnable(GL_LIGHT0);
}

void Maze::parseInput(const char *file)
{
    std::ifstream input(file);

    if (input)
    {
        std::string line;
        std::getline(input, line);
        std::istringstream sstream(line);
        sstream >> row >> col >> start_r >> start_c >> pos_r >> pos_c >> end_r >> end_c;
        GLuint intLine;

        while(std::getline(input, line))
        {
            sstream = std::istringstream(line);
            std::vector<GLuint> rowLine;
            while (sstream >> intLine)
            {
                rowLine.push_back(intLine);
            }
            maze.push_back(rowLine);
        }
        input.close();
    }
    else
    {
        std::cout << "Errore apertura file input." << std::endl;
    }
}
