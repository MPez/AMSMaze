/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#ifndef AMSMAZE_SUONO_H
#define AMSMAZE_SUONO_H


#include <AL/alut.h>
#include <GL/glut.h>
#include "Util.h"
#include "Maze.h"

/**
 * Classe adibita alla gestione degli allarmi
 *
 * @param listenerOrientation orientamento iniziale del giocatore
 * @param alarmBuffer1 buffer per il primo allarme
 * @param alarmSource sorgente del primo allarme
 * @param alarmBuffer1 buffer per il secondo allarme
 * @param alarmSource sorgente del secondo allarme
 * @param camera riferimento alla camera
 * @parma maze riferimento al labirinto
 */
class Suono {
private:
    ALfloat listenerOrientation[6];
    ALuint alarmBuffer1, alarmSource1;
    ALuint alarmBuffer2, alarmSource2;
    Camera &camera;
    Maze &maze;

public:
    Suono(Camera &camera, Maze &maze);
    ~Suono();

    /**
     * Riempe i buffer con gli allarmi e genera le sorgenti impostando la posizione.
     * Inizializza l'ascoltare e lo posiziona al punto di partenza del giocatore.
     */
    void impostaSuoni();

    /**
     * Spegne l'allarme relativo al parametro
     *
     * @param suono numero di allarme da spegnere
     */
    void spegniSuono(int suono);

    /**
     * Imposta il suono al punto di partenza con la corretta posizione e orientamento.
     */
    void setStart();

    /**
     * Imposta l'orientazione dell'ascoltatore secondo l'orientazione corrente del giocatore
     */
    void setOrientation();
};


#endif //AMSMAZE_SUONO_H
