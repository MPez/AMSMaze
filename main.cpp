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

Camera camera;
Maze maze = Maze(camera);
ResourceManager resourceManager = ResourceManager();

void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);
void IdleFunction();
void TimerFunction(int val);

int main(int argc, char *argv[])
{
    maze.parseInput(fileOutput);

    maze.setStart();

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
    if(startGioco && !endGioco)
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
    if(secondiAlTermine <= 0 && !endGioco)
    {
        maze.setStart();
        startGioco = false;
        char title[50];
        sprintf(title, "Posizione: %i, %i   -   ",
                (int) abs(camera.z), (int) abs(camera.x));
        strcat(title, titolo);
        glutSetWindowTitle(title);
    }

    if(maze.isExit((int) abs(round(camera.z + mysign(camera.z) * 0.5f)),
                   (int) abs(round(camera.x))))
    {
        if(!endGioco)
        {
            endGioco = true;
            tempoFine = glutGet(GLUT_ELAPSED_TIME);
        }
        char title[100];
        sprintf(title, "Vittoria!!!   -   Completato in %i secondi e %i tentativ%c   -   ",
            (tempoFine - tempoInizio) / 1000, tentativi, (tentativi > 1 ? 'i' : 'o'));
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

    glBindTexture(GL_TEXTURE_2D, 4);
    maze.disegnaPorte(dimCubo);

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
    gluPerspective(30, 1, 0.05, 15.0);
}


void AzioneTasto(unsigned char t, int , int)
{
    if(!startGioco)
    {
        startGioco = true;
        tempoInizio = glutGet(GLUT_ELAPSED_TIME);
        tentativi += 1;
    }

    switch(t)
    {
        case('w'):
        {
            GLfloat z = -spostamento * cos(camera.ay / pi_180);
            GLfloat x = -spostamento * sin(camera.ay / pi_180);
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        case('a'):
        {
            GLfloat x = -spostamento * cos(-camera.ay / pi_180);
            GLfloat z = -spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        case('s'):
        {
            GLfloat z = spostamento * cos(camera.ay / pi_180);
            GLfloat x = spostamento * sin(camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        case('d'):
        {
            GLfloat x = spostamento * cos(-camera.ay / pi_180);
            GLfloat z = spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

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












