//
// Created by marco on 07/06/16.
//

#ifndef AMSMAZE_RESOURCEMANAGER_H
#define AMSMAZE_RESOURCEMANAGER_H


#include <GL/glut.h>

class ResourceManager {
private:
    GLubyte mattoniTexture[256 * 256 * 3];
    GLubyte legnoTexture[256 * 256 * 3];

public:
    void caricaTexture();
    void ImpostaTexture();
};


#endif //AMSMAZE_RESOURCEMANAGER_H
