//
// Created by marco on 07/06/16.
//

#ifndef PROGETTO_CUBO_H
#define PROGETTO_CUBO_H

#include <GL/glut.h>

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

    virtual ~Cubo();

    static void impostaMateriale(char materiale);

    void disegna3();

    GLfloat getX() const {
        return x;
    }

    GLfloat getZ() const {
        return z;
    }

    GLfloat getL() const {
        return l;
    }

    GLfloat getW() const {
        return w;
    }
};

#endif //PROGETTO_CUBO_H
