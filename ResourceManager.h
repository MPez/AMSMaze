/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#ifndef AMSMAZE_RESOURCEMANAGER_H
#define AMSMAZE_RESOURCEMANAGER_H

#include <string>
#include <GL/glut.h>

/**
 * Classe che gestisce il caricamento e l'impostazione delle texture
 *
 * @param legnoFile file contenente texture legno per pavimento
 * @param legnoTexture texture legno per pavimento
 * @param brickFile file contenente texture mattoni per muri
 * @param brickTexture texture mattoni per muri
 * @param brickDoorFile file contenente texture per porta entrata
 * @param brickDoorTexture texture mattoni per porta entrata
 * @param brickExitDoorFile file contenente texture per porta uscita
 * @param brickExitDoorTexture texture mattoni per porta uscita
 * @param ceilConcreteFile file contenente texture per soffitto
 * @param ceilConcreteTexture texture per soffitto
 */
class ResourceManager {
private:

    const char *legnoFile = "res/1024/WoodFine0077_2_S.data";
    GLubyte legnoTexture[1024 * 1024 * 3];

    const char *brickFile = "res/1024/BrickSmallNew0034_1_S.data";
    GLubyte brickTexture[1024 * 1024 * 3];

    const char *brickDoorFile = "res/1024/BrickSmallNew0034_1_S_porta.data";
    GLubyte brickDoorTexture[1024 * 1024 * 3];

    const char *brickExitDoorFile = "res/1024/BrickSmallNew0034_1_S_porta_bronzo.data";
    GLubyte brickExitDoorTexture[1024 * 1024 * 3];

    const char *ceilConcreteFile = "res/512/PlasterWhite0074_S.data";
    GLubyte ceilConcreteTexture[512 * 512 * 3];


public:
    /**
     * Carica le texture da file
     */
    void caricaTexture();

    /**
     * Imposta le texture caricate nell'abiente
     */
    void impostaTexture();
};


#endif //AMSMAZE_RESOURCEMANAGER_H
