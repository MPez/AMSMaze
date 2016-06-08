/**
 * Labirinto 3D
 */

#include <cstdio>
#include <math.h>
#include <GL/glut.h>

#include "include/Game.h"
#include "include/Maze.h"
#include "include/Cubo.h"
#include "include/ResourceManager.h"
#include "include/Camera.h"

struct
{
    int prev_x = 0;
    int prev_z = 0;
    int cur_x = 0;
    int cur_z = 0;
} posizione;

Game game = Game();
Maze maze = Maze();
ResourceManager resourceManager = ResourceManager();
Camera camera = Camera();

void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);

int main(int argc, char *argv[])
{
    maze.parseInput(game.getFileInput());

    camera.x = maze.getStart_c() - 1.0f;
    camera.z = -maze.getStart_r() + 1.0f;
    camera.y = game.getDimCubo();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(450, 450);
    glutCreateWindow(game.getTitolo());

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
    glRotatef(-camera.ax, 1, 0, 0);
    glTranslatef(-camera.x, -camera.y, -camera.z);

    printf("x: %f, y: %f, z: %f, a: %f\n\n",
           camera.x, camera.y, camera.z, camera.ay);

    maze.disegnaLineePavimento();

    glEnable(GL_TEXTURE_2D);

    Cubo::impostaMateriale('m');
    glBindTexture(GL_TEXTURE_2D, 1);
    maze.disegnaMaze(game.getDimCubo());

    Cubo::impostaMateriale('l');
    glBindTexture(GL_TEXTURE_2D, 2);
    maze.disegnaPavimento(game.getDimCubo());



    glutSwapBuffers();
}

void CambiaDimensione(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.25, +0.25, -0.25, +0.25, 1, 100);
    //gluPerspective(30, 1.0, 1.0, 20.0);
}


void AzioneTasto(unsigned char t, int , int)
{
    switch(t)
    {
        case('w'):
        {
            GLfloat z = -game.getSpostamento() * cos(camera.ay / game.getPi_180());
            GLfloat x = -game.getSpostamento() * sin(camera.ay / game.getPi_180());
            printf("Spostamento x: %f, z: %f\n", x, z);
            if (maze.controllaSpostamento(x, z, camera))
            {
                camera.z += z;
                camera.x += x;
                printf("Passo avanti\n");
                //printf("Spostamento x: %f, z: %f\n", x, z);
                //aggiornaPosizione(x, z);
            } else
            {
                printf("Collisione muro avanti\n");
            }
        }
            break;
        case('a'):
        {
            GLfloat x = -game.getSpostamento() * cos(-camera.ay / game.getPi_180());
            GLfloat z = -game.getSpostamento() * sin(-camera.ay / game.getPi_180());
            printf("Spostamento x: %f, z: %f\n", x, z);
            if (maze.controllaSpostamento(x, z, camera))
            {
                camera.x += x;
                camera.z += z;
                printf("Passo sinistra\n");
            } else
            {
                printf("Collisione muro sinistra\n");
            }
            //printf("Spostamento x: %f, z: %f\n", x, z);
            //aggiornaPosizione(x, z);
        }
            break;
        case('s'):
        {
            GLfloat z = game.getSpostamento() * cos(camera.ay / game.getPi_180());
            GLfloat x = game.getSpostamento() * sin(camera.ay / game.getPi_180());
            printf("Spostamento x: %f, z: %f\n", x, z);
            if (maze.controllaSpostamento(x, z, camera))
            {
                camera.z += z;
                camera.x += x;
                printf("Passo indietro\n");
            } else
            {
                printf("Collisione muro indietro\n");
            }
            //printf("Spostamento x: %f, z: %f\n", x, z);
            //aggiornaPosizione(x, z);
        }
            break;
        case('d'):
        {
            GLfloat x = game.getSpostamento() * cos(-camera.ay / game.getPi_180());
            GLfloat z = game.getSpostamento() * sin(-camera.ay / game.getPi_180());
            printf("Spostamento x: %f, z: %f\n", x, z);
            if (maze.controllaSpostamento(x, z, camera))
            {
                camera.x += x;
                camera.z += z;
                printf("Passo destra\n");
            } else
            {
                printf("Collisione muro destra\n");
            }
            //printf("Spostamento x: %f, z: %f\n", x, z);
            //aggiornaPosizione(x, z);
        }
            break;
        case('q'):
            camera.ay += game.getAngolo();
            printf("Gira sinistra\n");
            break;
        case('e'):
            camera.ay -= game.getAngolo();
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












