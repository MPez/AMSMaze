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
    GLfloat dim;
    GLfloat l;
    GLfloat w;
    GLfloat h;

public:
    Cubo(GLfloat dim, GLfloat x, GLfloat y, GLfloat z);
    Cubo(GLfloat l, GLfloat w, GLfloat h, GLfloat x, GLfloat y, GLfloat z);

    virtual ~Cubo();

    static void impostaMateriale(char materiale);
    void disegna1();
    void disegna3();
};

#endif //PROGETTO_CUBO_H
