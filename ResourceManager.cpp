//
// Created by marco on 07/06/16.
//

#include <cstdio>
#include "ResourceManager.h"


void ResourceManager::caricaTexture()
{
    FILE *texture = fopen(mattoniFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture mattoni fallita.\n");
        return;
    }
    fread(mattoniTexture, 256 *256, 3, texture);
    fclose(texture);

    texture = fopen(legnoFile, "rb");
    if (texture == NULL) {
        printf("Apertura texture legno_256 fallita.\n");
        return;
    }
    fread(legnoTexture, 256 *256, 3, texture);
    fclose(texture);
}

void ResourceManager::impostaTexture()
{
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, mattoniTexture);

    glBindTexture(GL_TEXTURE_2D, 2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, legnoTexture);
}