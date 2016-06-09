#include <fstream>
#include <sstream>
#include <math.h>
#include <iostream>

#include "Maze.h"

Maze::Maze() { }

Maze::~Maze()
{
    for (int i = 0; i < cubi.size(); ++i) {
        delete cubi[i];
    }
}

void Maze::controllaSpostamento(GLfloat x, GLfloat z, Camera &camera)
{
    int i, j;

    i = (int) abs(round(camera.z + z + dimCamera * mysign(z)));
    j = (int) abs(round(camera.x + x + dimCamera * mysign(x)));


    printf("Controllo camera.z: %f, camera.x: %f, z: %f, x: %f, i:%i, j: %i\n",
           z, camera.z, x, camera.x, i, j);

    if(!maze[i][j])
    {
        camera.z += z;
        camera.x += x;
    }
    else
    {
    }
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
                cubi.push_back(cubo);
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