/*
 * Labirinto 3D
 * Progetto per insegnamento Sistemi Multimediali
 * Anno accademico 2015/2016
 * Pezzutti Marco 1084411
 */

#include "Suono.h"

Suono::Suono(Camera &camera, Maze &maze) : camera(camera), maze(maze)
{
    listenerOrientation[0] = 0.0f;
    listenerOrientation[1] = 0.0f;
    listenerOrientation[2] = -1.0f;
    listenerOrientation[3] = 0.0f;
    listenerOrientation[4] = 1.0f;
    listenerOrientation[5] = 0.0f;
}

Suono::~Suono() { }

void Suono::impostaSuoni()
{
    setStart();

    alarmBuffer1 = alutCreateBufferFromFile(militaryAlarmFile);
    alGenSources (1, &alarmSource1);
    alSourcei(alarmSource1, AL_BUFFER, alarmBuffer1);
    alSourcefv(alarmSource1, AL_POSITION, maze.getAlarmPosition1());
    alSourcei(alarmSource1, AL_LOOPING, AL_TRUE);
    alSourcef(alarmSource1, AL_ROLLOFF_FACTOR, 2.0f);
    alSourcePlay(alarmSource1);

    alarmBuffer2 = alutCreateBufferFromFile(militaryAlarmFile);
    alGenSources(1, &alarmSource2);
    alSourcei(alarmSource2, AL_BUFFER, alarmBuffer2);
    alSourcefv(alarmSource2, AL_POSITION, maze.getAlarmPosition2());
    alSourcei(alarmSource2, AL_LOOPING, AL_TRUE);
    alSourcef(alarmSource2, AL_ROLLOFF_FACTOR, 2.0f);
    alSourcePlay(alarmSource2);
}

void Suono::spegniSuono(int suono)
{
    switch (suono)
    {
        case 1:
            alSourceStop(alarmSource1);
            break;
        case 2:
            alSourceStop(alarmSource2);
            break;
    }
}

void Suono::setStart()
{
    alListener3f(AL_POSITION, camera.x, camera.y, camera.z);
    alListenerfv(AL_ORIENTATION, listenerOrientation);
}

void Suono::setOrientation()
{
    GLfloat mMatrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX,mMatrix);
    ALfloat listenerOrientation[] = {-mMatrix[2],-mMatrix[6],-mMatrix[10],
                                     mMatrix[1],mMatrix[5],mMatrix[9]};
    alListenerfv(AL_ORIENTATION, listenerOrientation);
}