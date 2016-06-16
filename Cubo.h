/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#ifndef PROGETTO_CUBO_H
#define PROGETTO_CUBO_H

#include <GL/glut.h>

/**
 * Classe che rappresenta un cubo, minima unità di costruzione del labirinto
 *
 * @param x indice posizione asse x
 * @param y indice posizione asse y
 * @param z indice posizione asse z
 * @param l dimensione lunghezza
 * @param w dimensione larghezza
 * @param h dimensione altezza
 * @param ambientMaterial valori luce ambientale
 * @param diffuseMaterial valori luce diffusa
 * @param specularMaterial_ceil valori luce speculare soffitto
 * @param specularMaterial_legno valori luce speculare pavimento
 * @param specularMaterial_brick valori luce speculare muri
 * @param shineMaterial valore brillantezza
 */
class Cubo {
private:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat l;
    GLfloat w;
    GLfloat h;

    static GLfloat ambientMaterial[];
    static GLfloat diffuseMaterial[];
    static GLfloat specularMaterial_ceil[];
    static GLfloat specularMaterial_legno[];
    static GLfloat specularMaterial_brick[];
    static GLfloat shineMaterial[];

public:
    Cubo(GLfloat dim, GLfloat x, GLfloat y, GLfloat z);
    Cubo(GLfloat l, GLfloat w, GLfloat h, GLfloat x, GLfloat y, GLfloat z);

    ~Cubo();

    /**
     * Imposta materiale del cubo
     *
     * @param materiale carattere per indicare il materiale da utilizzare
     */
    static void impostaMateriale(char materiale);

    /**
     * Disegna il cubo utilizzando gli attributi settati; vengono specificate singolarmente
     * ogni faccia con i relativi vertici, normale e texture
     */
    void disegna();

    /**
     * Imposta gli attributi di posizione del cubo
     *
     * @param x indice posizione asse x
     * @param y indice posizione asse y
     * @param z indice posizione asse z
     */
    void setPosizione(GLfloat x, GLfloat y, GLfloat z);
};

#endif //PROGETTO_CUBO_H
