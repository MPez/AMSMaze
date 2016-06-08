//
// Created by marco on 07/06/16.
//

#ifndef AMSMAZE_RESOURCEMANAGER_H
#define AMSMAZE_RESOURCEMANAGER_H

#include <string>
#include <GL/glut.h>

class ResourceManager {
private:
    const char *mattoniFile = "res/mattoni.raw";
    const char *legnoFile = "res/legno_256.raw";
    GLubyte mattoniTexture[256 * 256 * 3];
    GLubyte legnoTexture[256 * 256 * 3];

public:
    void caricaTexture();
    void impostaTexture();
};


#endif //AMSMAZE_RESOURCEMANAGER_H
