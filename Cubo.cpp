/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#include "Cubo.h"

Cubo::Cubo(GLfloat dim, GLfloat x, GLfloat y, GLfloat z)
        : l(dim), w(dim), h(dim), x(x), y(y), z(z) {}

Cubo::Cubo(GLfloat l, GLfloat w, GLfloat h, GLfloat x, GLfloat y, GLfloat z)
        : l(l), w(w), h(h), x(x), y(y), z(z) {}

Cubo::~Cubo() {}

GLfloat Cubo::ambientMaterial[] = {1.0, 1.0, 1.0, 1.0};
GLfloat Cubo::diffuseMaterial[] = {1.0, 1.0, 1.0, 1.0};
GLfloat Cubo::specularMaterial_ceil[] = {1.0, 1.0, 1.0, 1.0};
GLfloat Cubo::specularMaterial_legno[] = {0.6, 1.0, 0.7, 1.0};
GLfloat Cubo::specularMaterial_brick[] = {0.5, 0.6, 0.6, 1.0};
GLfloat Cubo::shineMaterial[] = {20.0};

void Cubo::impostaMateriale(char materiale)
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);

    switch(materiale) {
        case 'c':
            glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial_ceil);
            break;
        case 'l':
            glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial_legno);
            break;
        case 'b':
            glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial_brick);
            break;
    }

    glMaterialfv(GL_FRONT, GL_SHININESS, shineMaterial);
}

void Cubo::setPosizione(GLfloat x, GLfloat y, GLfloat z)
{
    Cubo::x = x;
    Cubo::y = y;
    Cubo::z = z;
}

void Cubo::disegna()
{
    glPushMatrix();

    glTranslatef(x, y, z);

    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 0);
    glVertex3f(l, h, w);
    glTexCoord2f(1, 0);
    glVertex3f(-l, h, w);
    glTexCoord2f(1, 1);
    glVertex3f(-l, -h, w);
    glTexCoord2f(0, 1);
    glVertex3f(l, -h, w);

    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 0);
    glVertex3f(-l, h, -w);
    glTexCoord2f(1, 0);
    glVertex3f(l, h, -w);
    glTexCoord2f(1, 1);
    glVertex3f(l, -h, -w);
    glTexCoord2f(0, 1);
    glVertex3f(-l, -h, -w);

    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(l, h, -w);
    glTexCoord2f(1, 0);
    glVertex3f(l, h, w);
    glTexCoord2f(1, 1);
    glVertex3f(l, -h, w);
    glTexCoord2f(0, 1);
    glVertex3f(l, -h, -w);

    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-l, h, w);
    glTexCoord2f(1, 0);
    glVertex3f(-l, h, -w);
    glTexCoord2f(1, 1);
    glVertex3f(-l, -h, -w);
    glTexCoord2f(0, 1);
    glVertex3f(-l, -h, w);

    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(l, h, -w);
    glTexCoord2f(1, 0);
    glVertex3f(-l, h, -w);
    glTexCoord2f(1, 1);
    glVertex3f(-l, h, w);
    glTexCoord2f(0, 1);
    glVertex3f(l, h, w);

    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-l, -h, -w);
    glTexCoord2f(1, 0);
    glVertex3f(l, -h, -w);
    glTexCoord2f(1, 1);
    glVertex3f(l, -h, w);
    glTexCoord2f(0, 1);
    glVertex3f(-l, -h, w);

    glEnd();

    glPopMatrix();
}