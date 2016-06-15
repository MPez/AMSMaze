//
// Created by marco on 07/06/16.
//

#ifndef AMSMAZE_RESOURCEMANAGER_H
#define AMSMAZE_RESOURCEMANAGER_H

#include <string>
#include <GL/glut.h>

class ResourceManager {
private:

    const char *legnoFile = "res/1024/WoodFine0077_2_S.data";
    GLubyte legnoTexture[1024 * 1024 * 3];

    const char *brickFile = "res/1024/BrickSmallNew0034_1_S.data";
    GLubyte brickTexture[1024 * 1024 * 3];

    const char *brickDoorFile = "res/1024/BrickSmallNew0034_1_S_porta.data";
    GLubyte brickDoorTexture[1024 * 1024 * 3];

    const char *ceilConcreteFile = "res/512/PlasterWhite0074_S.data";
    GLubyte ceilConcreteTexture[512 * 512 * 3];


public:
    void caricaTexture();
    void impostaTexture();
};


#endif //AMSMAZE_RESOURCEMANAGER_H
