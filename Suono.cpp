//
// Created by marco on 18/06/16.
//

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
    alListener3f(AL_POSITION, camera.x, camera.y, camera.z);
    alListenerfv(AL_ORIENTATION, listenerOrientation);

    militaryBuffer = alutCreateBufferFromFile(militaryAlarmFile);
    alGenSources (1, &militarySource);
    alSourcei(militarySource, AL_BUFFER, militaryBuffer);
    alSourcefv(militarySource, AL_POSITION, maze.getMilitaryPos());
    alSourcei(militarySource, AL_LOOPING, AL_TRUE);
    alSourcef(militarySource, AL_ROLLOFF_FACTOR, 2.0f);
    alSourcePlay(militarySource);

    alarmBuffer = alutCreateBufferFromFile(militaryAlarmFile);
    alGenSources(1, &alarmSource);
    alSourcei(alarmSource, AL_BUFFER, alarmBuffer);
    alSourcefv(alarmSource, AL_POSITION, maze.getAlarmPos());
    alSourcei(alarmSource, AL_LOOPING, AL_TRUE);
    alSourcef(alarmSource, AL_ROLLOFF_FACTOR, 2.0f);
    //alSourcef(alarmBuffer, AL_MAX_GAIN, 0.5f);
    alSourcePlay(alarmSource);
}

void Suono::spegniSuono(int suono)
{
    switch (suono)
    {
        case 1:
            alSourceStop(militarySource);
            break;
        case 2:
            alSourceStop(alarmSource);
            break;
    }
}