/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#ifndef PROGETTO_MAZE_H
#define PROGETTO_MAZE_H

#include <GL/glut.h>
#include <AL/alut.h>
#include <vector>
#include <string>
#include "Util.h"
#include "Cubo.h"

/**
 * Classe che rappresenta il labirinto
 *
 * @param row numero righe del labirinto
 * @param col numero colonne del labirinto
 * @param start_r indice riga dell'ingresso del labirinto
 * @param start_c indice colonna dell'ingresso del labirinto
 * @param pos_r indice riga del punto di partenza del giocatore
 * @param pos_c indice colonna del punto di partenza del giocatore
 * @param end_r indice riga dell'uscita del labirinto
 * @param end_c indice colonna dell'uscita del labirinto
 * @param maze matrice posizione muri
 * @param camera riferimento alla camera
 */
class Maze {
private:
    GLuint row;
    GLuint col;
    GLfloat start_r;
    GLfloat start_c;
    GLfloat pos_r;
    GLfloat pos_c;
    GLfloat end_r;
    GLfloat end_c;
    ALfloat militaryPos[3];
    ALfloat alarmPos[3];
    std::vector<std::vector<GLuint>> maze;
    Camera &camera;

public:
    Maze(Camera &camera);
    ~Maze();

    /**
     * Disegna i muri del labirinto usando cubi
     *
     * @param dim dimensione del cubo
     */
    void disegnaMaze(GLfloat dim);

    /**
     * Disegna la porta di ingresso del labirinto
     *
     * @param dim dimensione del cubo
     */
    void disegnaPortaStart(GLfloat dim);

    /**
     * Disegna la porta di uscita del labirinto
     *
     * @param dim dimensione del cubo
     */
    void disegnaPortaEnd(GLfloat dim);

    /**
     * Disegna il pavimento del labirinto usando cubi
     *
     * @param dim dimensione del cubo
     */
    void disegnaPavimento(GLfloat dim);

    /**
     * Disegna il soffitto del labirinto usando cubi
     *
     * @param dim dimensione del cubo
     */
    void disegnaSoffitto(GLfloat dim);

    /**
     * Disegna la spotlight che illumina il labirinto dal punto di vista del giocatore
     */
    void disegnaLuci();

    /**
     * Controlla che lo spostamento richiesto dal giocatore sia possibile individuando
     * collisioni con i muri ed esegue il movimento in caso negativo
     *
     * @param x spostamento lungo l'asse x del sistema di riferimento
     * @param z spostamento lungo l'asse z del sistema di riferimento
     */
    void eseguiSpostamento(GLfloat x, GLfloat z);

    /**
     * Legge il file di input del labirinto settando gli attributi
     *
     * @param file path file di input
     */
    void parseInput(const char *file);

    /**
     * Imposta il punto di partenza del giocatore
     */
    void setStart();

    /**
     * Controlla se la casella di indici i, j è l'uscita
     *
     * @param i indice di riga del labirinto
     * @param j indice di colonna del labirinto
     */
    bool isExit(int i, int j);

    /**
     * Controlla se la casella di indici i, j è l'entrata
     *
     * @param i indice di riga del labirinto
     * @param j indice di colonna del labirinto
     */
    bool isEntrance(int i, int j);

    const ALfloat *getMilitaryPos() const {
        return militaryPos;
    }

    const ALfloat *getAlarmPos() const {
        return alarmPos;
    }

    void disegnaAllarmi(GLfloat dim, int alarm);

    int isAlarm(int i, int j);
};

#endif //PROGETTO_MAZE_H
