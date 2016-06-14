/**
 * Labirinto 3D
 */

#include <cstdio>
#include <math.h>
#include <GL/glut.h>
#include <cstring>

#include "Cubo.h"
#include "ResourceManager.h"
#include "Maze.h"

Maze maze = Maze();
ResourceManager resourceManager = ResourceManager();
Camera camera;

GLfloat tempo = 0.0f;

void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);
void IdleFunction();
void TimerFunction(int val);

int main(int argc, char *argv[])
{
    //srand(time(NULL));

    //maze.generaMaze();
    //maze.stampaMaze();
    maze.parseInput(fileInput);

    camera.x = maze.getStart_c() - 1.0f;
    camera.z = -maze.getStart_r() + 1.0f;
    camera.y = dimCubo;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(titolo);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    GLfloat global[] = { 0.1, 0.1, 0.1, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    maze.disegnaLuci();

    resourceManager.caricaTexture();
    resourceManager.impostaTexture();

    glutReshapeFunc(CambiaDimensione);
    glutDisplayFunc(DisegnaTutto);
    glutKeyboardFunc(AzioneTasto);
    glutIdleFunc(IdleFunction);
    glutTimerFunc(0, TimerFunction, 0);

    glutMainLoop();

    return 0;
}

void TimerFunction(int val)
{
    if(startGioco)
    {
        tempoTrascorso = glutGet(GLUT_ELAPSED_TIME);
        secondiAlTermine = (tempoGioco - tempoTrascorso + tempoInizio) / 1000;
        char title[50];
        sprintf(title, "Tempo: %i   -   Posizione: %i, %i   -   ",
                secondiAlTermine, (int) abs(camera.z), (int) abs(camera.x));
        strcat(title, titolo);
        glutSetWindowTitle(title);
        glutTimerFunc(250, TimerFunction, 0);
    }
    else
    {
        glutTimerFunc(0, TimerFunction, 0);
    }
}

void IdleFunction()
{
    if(secondiAlTermine <= 0)
    {
        camera.x = maze.getStart_c() - 1.0f;
        camera.z = -maze.getStart_r() + 1.0f;
        camera.y = dimCubo;
        camera.ay = 0;
        startGioco = false;
        char title[50];
        sprintf(title, "Posizione: %i, %i   -   ",
                (int) abs(camera.z), (int) abs(camera.x));
        strcat(title, titolo);
        glutSetWindowTitle(title);
    }
    glutPostRedisplay();
}

void DisegnaTutto()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-camera.ay, 0, 1, 0);
    glTranslatef(-camera.x, -camera.y, -camera.z);

    //printf("Posizione z: %f, x: %f, y: %f, a: %f\n\n",
    //       camera.z, camera.x, camera.y, camera.ay);

    //maze.disegnaLineePavimento();


    glEnable(GL_TEXTURE_2D);

    Cubo::impostaMateriale('b');
    glBindTexture(GL_TEXTURE_2D, 3);
    maze.disegnaMaze(dimCubo);

    Cubo::impostaMateriale('l');
    glBindTexture(GL_TEXTURE_2D, 2);
    maze.disegnaPavimento(dimCubo);

    Cubo::impostaMateriale('c');
    glBindTexture(GL_TEXTURE_2D, 5);
    maze.disegnaSoffitto(dimCubo);

    glutSwapBuffers();
}

void CambiaDimensione(int width, int height)
{
    GLfloat r = (GLfloat) height / (GLfloat) width;

    if(width < height)
    {
        glViewport(0, (height - width)/2, width, width);
    }
    else
    {
        if(width > height)
        {
            glViewport((width - height)/2, 0, height, height);
        }
        else
        {
            glViewport(0, 0, width, height);
        }
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 100);
    gluPerspective(30, r, 0.05, 30.0);
}


void AzioneTasto(unsigned char t, int , int)
{
    if(!startGioco)
    {
        startGioco = true;
        tempoInizio = glutGet(GLUT_ELAPSED_TIME);
    }

    switch(t)
    {
        case('w'):
        {
            GLfloat z = -spostamento * cos(camera.ay / pi_180);
            GLfloat x = -spostamento * sin(camera.ay / pi_180);
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z, camera);

        }
            break;
        case('a'):
        {
            GLfloat x = -spostamento * cos(-camera.ay / pi_180);
            GLfloat z = -spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z, camera);

        }
            break;
        case('s'):
        {
            GLfloat z = spostamento * cos(camera.ay / pi_180);
            GLfloat x = spostamento * sin(camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z, camera);

        }
            break;
        case('d'):
        {
            GLfloat x = spostamento * cos(-camera.ay / pi_180);
            GLfloat z = spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z, camera);

        }
            break;
        case('q'):
            camera.ay += angolo;
            //printf("Gira sinistra\n");
            break;
        case('e'):
            camera.ay -= angolo;
            //printf("Gira destra\n");
            break;
        case('z'):
            camera.y -= 0.5;
            //printf("Scendi\n");
            break;
        case('c'):
            camera.y += 0.5;
            //printf("Sali\n");
            break;
    }

    glutPostRedisplay();
}












