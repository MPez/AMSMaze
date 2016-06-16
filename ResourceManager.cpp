/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#include <cstdio>
#include "ResourceManager.h"


void ResourceManager::caricaTexture()
{
    FILE *texture;

    texture = fopen(legnoFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture legno_256 fallita.\n");
        return;
    }
    fread(legnoTexture, 1024 * 1024, 3, texture);
    fclose(texture);

    texture = fopen(brickFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture brickSmall fallita.\n");
        return;
    }
    fread(brickTexture, 1024 * 1024, 3, texture);
    fclose(texture);

    texture = fopen(brickDoorFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture brickDoor fallita.\n");
        return;
    }
    fread(brickDoorTexture, 1024 * 1024, 3, texture);
    fclose(texture);

    texture = fopen(brickExitDoorFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture brickExitDoor fallita.\n");
        return;
    }
    fread(brickExitDoorTexture, 1024 * 1024, 3, texture);
    fclose(texture);

    texture = fopen(ceilConcreteFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture ceilConcrete fallita.\n");
        return;
    }
    fread(ceilConcreteTexture, 512 * 512, 3, texture);
    fclose(texture);
}

void ResourceManager::impostaTexture()
{
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, legnoTexture);

    glBindTexture(GL_TEXTURE_2D, 2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, brickTexture);

    glBindTexture(GL_TEXTURE_2D, 3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, brickDoorTexture);

    glBindTexture(GL_TEXTURE_2D, 4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, brickExitDoorTexture);

    glBindTexture(GL_TEXTURE_2D, 5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, ceilConcreteTexture);
}