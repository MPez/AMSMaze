#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>

#include "include/Maze.h"
#include "include/Cubo.h"
#include "include/Camera.h"

Maze::Maze() { }

Maze::~Maze() { }

bool Maze::controllaSpostamento(GLfloat x, GLfloat z, Camera camera)
{
    int i;
    int j;

    i = (int) abs(round(camera.z + z));
    j = (int) abs(round(camera.x + x));


    printf("Controllo camera.z: %f, z: %f, camera.x: %f x: %f, i:%i, j: %i\n",
           z, camera.z, x, camera.x, i, j);

    if (!maze[i][j])
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
                Cubo cubo(dim, j, dim, -i - 1.0f);
                cubo.disegna1();
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
            Cubo cubo1(dim, dim, 0.05f, j, -0.05f, -i - 1.0f);
            cubo1.disegna3();
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
    glEnable(GL_LIGHT0);

    GLfloat lightPosition[] = {10.0, 10.0, 0.0, 0.0};
    GLfloat ambientLight[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuseLight[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specularLight[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void Maze::parseInput(const char *file)
{
    std::ifstream input(file);

    if (input)
    {
        std::string line;
        std::getline(input, line);
        std::istringstream sstream(line);
        sstream >> row >> col >> start_r >> start_c;
        GLuint intLine;

        while(std::getline(input, line))
        {
            sstream = std::istringstream(line);
            std::vector<GLuint> rowLine;
            while (sstream >> intLine)
            {
                rowLine.push_back(intLine);
                std::cout << intLine;
            }
            std::cout << std::endl;
            maze.push_back(rowLine);
        }
    }
    else
    {
        std::cout << "Errore apertura file input." << std::endl;
    }

    input.close();
}