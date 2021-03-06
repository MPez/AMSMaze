/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#ifndef AMSMAZE_UTIL_H
#define AMSMAZE_UTIL_H

/*
 * Costanti globali
 */
static const GLchar *titolo = "AMSMaze";
static const GLchar *fileInput = "res/input_maze.txt";
static const GLchar *fileInputBig = "res/input_maze_big.txt";
static const int windowWidth = 600;
static const int windowHeight = 600;
static const int windowPosX = 100;
static const int windowPosY = 100;

static const GLfloat pi_180 = 180.0f / 3.141592f;
static const GLfloat dimCubo = 0.5f;
static const GLfloat dimCamera = 0.07f;
static const GLfloat spostamento = 0.25f;
static const GLfloat angolo = 2.5f;

static const char *militaryAlarmFile = "res/96973__kizilsungur__military-alarm.wav";

/*
 * Variabili globali
 */
static int tempoGioco = 5 * 60 * 1000;
static bool startGioco = false;
static bool endGioco = false;
static bool restart = false;
static int secondiAlTermine = 0;
static int tempoTrascorso = 0;
static int tempoInizio = 0;
static int tempoFine = 0;
static int tentativi = 0;

static bool alarmOn1 = 1;
static bool alarmOn2 = 1;
static int allarmiRimanenti = 2;

/*
 * Struttura che rappresenta la posizione della camera/giocatore
 */
struct Camera
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float ay = 0.0f;
};

/*
 * Ritorna il segno del parametro
 */
inline GLfloat mysign(GLfloat f)
{
    if(f > 0.0)
    {
        return 1.0f;
    }
    return (f == 0.0f) ? 0.0f : -1.0f;
}

#endif //AMSMAZE_UTIL_H
