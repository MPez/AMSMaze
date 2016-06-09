/**
 * Labirinto 3D
 */

#include <cstdio>
#include <math.h>
#include <GL/glut.h>

#include "Cubo.h"
#include "ResourceManager.h"
#include "Maze.h"

Maze maze = Maze();
ResourceManager resourceManager = ResourceManager();
Camera camera;

void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);

int main(int argc, char *argv[])
{
    maze.parseInput(fileInput);

    camera.x = maze.getStart_c() - 1.0f;
    camera.z = -maze.getStart_r() + 1.0f;
    camera.y = dimCubo;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(450, 450);
    glutCreateWindow(titolo);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    maze.disegnaLuci();
    resourceManager.caricaTexture();
    resourceManager.impostaTexture();

    glutReshapeFunc(CambiaDimensione);
    glutDisplayFunc(DisegnaTutto);
    glutKeyboardFunc(AzioneTasto);

    glutMainLoop();

    return 0;
}

void DisegnaTutto()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-camera.ay, 0, 1, 0);
    glTranslatef(-camera.x, -camera.y, -camera.z);

    printf("Posizione z: %f, x: %f, y: %f, a: %f\n\n",
           camera.z, camera.x, camera.y, camera.ay);

    maze.disegnaLineePavimento();

    glEnable(GL_TEXTURE_2D);

    Cubo::impostaMateriale('m');
    glBindTexture(GL_TEXTURE_2D, 1);
    maze.disegnaMaze(dimCubo);

    Cubo::impostaMateriale('l');
    glBindTexture(GL_TEXTURE_2D, 2);
    maze.disegnaPavimento(dimCubo);



    glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
    if(w < h)
    {
        glViewport(0, (h - w)/2, w, w);
    }
    else
    {
        if(w > h)
        {
            glViewport((w - h)/2, 0, h, h);
        }
        else
        {
            glViewport(0, 0, w, h);
        }
    }



    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 100);
    gluPerspective(30, 1.0, 0.05, 30.0);
}


void AzioneTasto(unsigned char t, int , int)
{
    switch(t)
    {
        case('w'):
        {
            GLfloat z = -spostamento * cos(camera.ay / pi_180);
            GLfloat x = -spostamento * sin(camera.ay / pi_180);
            printf("Spostamento z: %f, x: %f\n", z, x);
            maze.controllaSpostamento(x, z, camera);

        }
            break;
        case('a'):
        {
            GLfloat x = -spostamento * cos(-camera.ay / pi_180);
            GLfloat z = -spostamento * sin(-camera.ay / pi_180);;
            printf("Spostamento z: %f, x: %f\n", z, x);
            maze.controllaSpostamento(x, z, camera);

        }
            break;
        case('s'):
        {
            GLfloat z = spostamento * cos(camera.ay / pi_180);
            GLfloat x = spostamento * sin(camera.ay / pi_180);;
            printf("Spostamento z: %f, x: %f\n", z, x);
            maze.controllaSpostamento(x, z, camera);

        }
            break;
        case('d'):
        {
            GLfloat x = spostamento * cos(-camera.ay / pi_180);
            GLfloat z = spostamento * sin(-camera.ay / pi_180);;
            printf("Spostamento z: %f, x: %f\n", z, x);
            maze.controllaSpostamento(x, z, camera);

        }
            break;
        case('q'):
            camera.ay += angolo;
            printf("Gira sinistra\n");
            break;
        case('e'):
            camera.ay -= angolo;
            printf("Gira destra\n");
            break;
        case('z'):
            camera.y -= 0.5;
            printf("Scendi\n");
            break;
        case('c'):
            camera.y += 0.5;
            printf("Sali\n");
            break;
    }

    glutPostRedisplay();
}












