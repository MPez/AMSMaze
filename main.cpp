/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#include <cstdio>
#include <math.h>
#include <cstring>
#include <GL/glut.h>
#include <AL/alut.h>

#include "Cubo.h"
#include "ResourceManager.h"
#include "Maze.h"
#include "Suono.h"

/*
 * Inizializzazione oggetti globali
 */
Camera camera;
Maze maze = Maze(camera);
ResourceManager resourceManager = ResourceManager();
Suono suono = Suono(camera, maze);

GLuint mazeList, ceilList;

/*
 * Definizione funzioni callback usate nel main loop
 */
void CambiaDimensione(int width, int height);
void DisegnaTutto();
void AzioneTasto(unsigned char tasto, int x, int y);
void IdleFunction();
void TimerFunction(int val);

void disegnaMazeList()
{
    Cubo::impostaMateriale('b');
    glBindTexture(GL_TEXTURE_2D, 2);
    maze.disegnaMaze(dimCubo);

    glBindTexture(GL_TEXTURE_2D, 3);
    maze.disegnaPortaStart(dimCubo);

    glBindTexture(GL_TEXTURE_2D, 4);
    maze.disegnaPortaEnd(dimCubo);

    Cubo::impostaMateriale('l');
    glBindTexture(GL_TEXTURE_2D, 1);
    maze.disegnaPavimento(dimCubo);
}

void disegnaCeilList()
{
    Cubo::impostaMateriale('c');
    glBindTexture(GL_TEXTURE_2D, 5);
    maze.disegnaSoffitto(dimCubo);
}

int main(int argc, char *argv[])
{
    /*
     * Lettura labirinto da file pre-generato
     */
    maze.parseInput(fileInput);

    /*
     * Impostazione punto di partenza dell'utente (camera) nel labirinto
     */
    maze.setStart();

    /*
     * Inizializzazione ambiente openGL e creazione finestra applicazione
     */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowPosition(windowPosX, windowPosY);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow(titolo);

    /*
     * Inizializzazione ambiente openAL
     */
    alutInit (&argc, argv);
    suono.impostaSuoni();

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    /*
     * Impostazione luce globale
     */
    GLfloat global[] = { 0.1, 0.1, 0.1, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);

    /*
     * Colore di sfondo finestra
     */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    /*
     * Impostazione spotlight
     */
    maze.disegnaLuci();

    /*
     * Caricamento e impostazione texture
     */
    resourceManager.caricaTexture();
    resourceManager.impostaTexture();

    mazeList = glGenLists(1);
    glNewList(mazeList, GL_COMPILE);
    disegnaMazeList();
    glEndList();

    ceilList = glGenLists(1);
    glNewList(ceilList, GL_COMPILE);
    disegnaCeilList();
    glEndList();

    /*
     * Impostazione funzioni callback
     */
    glutReshapeFunc(CambiaDimensione);
    glutDisplayFunc(DisegnaTutto);
    glutKeyboardFunc(AzioneTasto);
    glutIdleFunc(IdleFunction);
    glutTimerFunc(0, TimerFunction, 0);

    glutMainLoop();

    return 0;
}

/*
 * Timer utilizzato per calcolare e visualizzare il tempo trascorso nel gioco
 */
void TimerFunction(int val)
{
    // gioco iniziato ma non è stata trovata l'uscita
    if(startGioco && !endGioco)
    {
        tempoTrascorso = glutGet(GLUT_ELAPSED_TIME);
        secondiAlTermine = (tempoGioco - tempoTrascorso + tempoInizio) / 1000;
        char title[50];
        sprintf(title, "Tempo: %i  -  Posizione: %i, %i  -  Allarmi: %i  -  ",
                secondiAlTermine, (int) abs(round(camera.z)), (int) abs(round(camera.x)),
        allarmiRimanenti);
        strcat(title, titolo);
        glutSetWindowTitle(title);
        glutTimerFunc(250, TimerFunction, 0);
    }
    else
    {
        glutTimerFunc(0, TimerFunction, 0);
    }
}

/*
 * Tiene traccia del tempo che scorre e resetta il giocatore al punto di partenza al termine
 * del tempo fissato se non è stata trovata l'uscita; incrementa il tempo di gioco
 * ad ogni tentativo fallito.
 *
 * Controlla se viene raggiunta l'uscita e fa terminare il gioco avvisando l'utente, che resta
 * comunque libero di esplorare il labirinto.
 * Visualizza sulla barra del titolo il tempo di completamento e il numero di tentativi eseguiti.
 *
 * Controlla se il giocatore è in una casella di allarme e in caso affermativo lo spegne.
 */
void IdleFunction()
{
    if(secondiAlTermine <= 0 && !endGioco && restart)
    {
        maze.setStart();
        suono.setStart();
        startGioco = false;
        restart = false;
        tempoGioco += 1 * 60 * 1000;
        char title[50];
        sprintf(title, "Posizione: %i, %i  -  ",
                (int) abs(camera.z), (int) abs(camera.x));
        strcat(title, titolo);
        glutSetWindowTitle(title);
    }

    if(maze.isExit((int) abs(round(camera.z + mysign(camera.z) * 0.5f)),
                   (int) abs(round(camera.x))) &&
            !alarmOn1 && !alarmOn2)
    {
        if(!endGioco)
        {
            endGioco = true;
            tempoFine = glutGet(GLUT_ELAPSED_TIME);
        }
        char title[100];
        sprintf(title, "Vittoria!!!  -  Completato in %i secondi e %i tentativ%c  -  ",
            (tempoFine - tempoInizio) / 1000, tentativi, (tentativi > 1 ? 'i' : 'o'));
        strcat(title, titolo);
        glutSetWindowTitle(title);
    }

    if(alarmOn1 || alarmOn2)
    {
        int alarm = maze.isAlarm((int) abs(round(camera.z)), (int) abs(round(camera.x)));
        switch (alarm)
        {
            case 0:
                break;
            case 1:
                if(alarmOn1)
                {
                    allarmiRimanenti -= 1;
                    alarmOn1 = 0;
                    suono.spegniSuono(1);
                }
                break;
            case 2:
                if(alarmOn2)
                {
                    allarmiRimanenti -= 1;
                    alarmOn2 = 0;
                    suono.spegniSuono(2);
                }
                break;
        }

    }

    glutPostRedisplay();
}

/*
 * Esegue gli spostamenti del giocatore (camera): traslazioni e rotazioni.
 *
 * Disegna i cubi che compongono il labirinto, il pavimento ed il soffitto impostando materiali
 * e texture; nella posizione degli allarmi viene applicata una texture diversa fintanto che
 * l'allarme è attivo.
 */
void DisegnaTutto()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-camera.ay, 0, 1, 0);
    glTranslatef(-camera.x, -camera.y, -camera.z);
    suono.setOrientation();

    //printf("Posizione z: %f, x: %f, y: %f, a: %f\n\n",
    //       camera.z, camera.x, camera.y, camera.ay);

    //maze.disegnaLineePavimento();


    glEnable(GL_TEXTURE_2D);

    glCallList(mazeList);

    if(alarmOn1)
    {
        glBindTexture(GL_TEXTURE_2D, 6);
    }
    maze.disegnaAllarmi(dimCubo, 1);

    if(!alarmOn2)
    {
        glBindTexture(GL_TEXTURE_2D, 1);
    }
    maze.disegnaAllarmi(dimCubo, 2);

    glCallList(ceilList);

    glutSwapBuffers();
}

/*
 * Gestisce il ridimensionamento della finestra e imposta la prospettiva della camera.
 */
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

/*
 * Al primo movimento del giocatore fa iniziare il gioco.
 * Gestisce i comandi impartiti dal giocatore impostando gli spostamenti corretti.
 */
void AzioneTasto(unsigned char t, int , int)
{
    if(!startGioco)
    {
        startGioco = true;
        restart = true;
        tempoInizio = glutGet(GLUT_ELAPSED_TIME);
        tentativi += 1;
    }

    switch(t)
    {
        /*
         * avanti
         */
        case('w'):
        {
            GLfloat z = -spostamento * cos(camera.ay / pi_180);
            GLfloat x = -spostamento * sin(camera.ay / pi_180);
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        /*
         * sinistra
         */
        case('a'):
        {
            GLfloat x = -spostamento * cos(-camera.ay / pi_180);
            GLfloat z = -spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        /*
         * indietro
         */
        case('s'):
        {
            GLfloat z = spostamento * cos(camera.ay / pi_180);
            GLfloat x = spostamento * sin(camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        /*
         * destra
         */
        case('d'):
        {
            GLfloat x = spostamento * cos(-camera.ay / pi_180);
            GLfloat z = spostamento * sin(-camera.ay / pi_180);;
            //printf("Spostamento z: %f, x: %f\n", z, x);
            maze.eseguiSpostamento(x, z);

        }
            break;
        /*
         * ruota sinistra
         */
        case('q'):
        {
            camera.ay += angolo;
            //printf("Gira sinistra\n");
        }
            break;
        /*
         * ruota destra
         */
        case('e'):
        {
            camera.ay -= angolo;
            //printf("Gira destra\n");
        }
            break;
    }
    glutPostRedisplay();
}













