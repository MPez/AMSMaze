//
// Created by marco on 07/06/16.
//

#include <cstdio>
#include "ResourceManager.h"


void ResourceManager::caricaTexture()
{
    FILE *texture = fopen("mattoni.raw", "rb");
    if (texture == NULL) {
        printf("Apertura texture mattoni fallita.\n");
        return;
    }
    fread(mattoniTexture, 256 *256, 3, texture);
    fclose(texture);

    texture = fopen("legno_256.raw", "rb");
    if (texture == NULL) {
        printf("Apertura texture legno_256 fallita.\n");
        return;
    }
    fread(legnoTexture, 256 *256, 3, texture);
    fclose(texture);
}

void ResourceManager::ImpostaTexture()
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