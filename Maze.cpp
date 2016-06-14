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

    i = (int) abs(round(camera.z + z + dimCamera * mysign(z)));
    j = (int) abs(round(camera.x + x + dimCamera * mysign(x)));


    //printf("Controllo camera.z: %f, camera.x: %f, z: %f, x: %f, i:%i, j: %i\n",
    //       z, camera.z, x, camera.x, i, j);

    if(!maze[i][j])
    {
        camera.z += z;
        camera.x += x;
    }
    else
    {
        //printf("collisione!!\n");
    }
}

void Maze::setStart()
{
    camera.x = start_c;
    camera.z = -start_r;
    camera.y = dimCubo;
    camera.ay = 0.0f;
}

bool Maze::isExit()
{
    if((int) abs(round(camera.z)) == end_r && (int) abs(round(camera.x)) == end_c)
    {
        return true;
    }
    return false;
}

void Maze::disegnaMaze(GLfloat dim)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (maze[i][j])
            {
                Cubo *cubo = new Cubo(dim, j, dim, -i);
                cubo->disegna3();
            }
        }
    }
}

void Maze::disegnaPavimento(GLfloat dim)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            Cubo cubo(dim, dim, 0.05f, j, -0.05f, -i);
            cubo.disegna3();
        }
    }
}

void Maze::disegnaSoffitto(GLfloat dim)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            Cubo cubo(dim, dim, 0.05f, j, 1.05f, -i);
            cubo.disegna3();
        }
    }
}

void Maze::disegnaLineePavimento() {
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    for(GLfloat i = -200; i < 200; i += 1) {
        glVertex3f(-200, 0, i);
        glVertex3f(200, 0, i);
    }

    for(GLfloat i = -200; i < 200; i += 1) {
        glVertex3f(i, 0, -200);
        glVertex3f(i, 0, 200);
    }

    glEnd();
}

void Maze::disegnaLuci()
{
    GLfloat lightPosition[] = {0.0f, 0.0f, 2.0f, 1.0f};
    GLfloat spotDirection[] = {0.0f, 0.0f, -1.0f};

    GLfloat ambientLight[] = {1.0f, 1.0f, 0.6f, 1.0f};
    GLfloat diffuseLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
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
        sstream >> row >> col >> start_r >> start_c >> end_r >> end_c;
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
