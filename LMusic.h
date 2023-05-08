#ifndef LMUSIC_H
#define LMUSIC_H

#include <SDL_mixer.h>
#include <SDL.h>

#include <string>
#include <iostream>

class LMusic {
    public:
        LMusic();

        bool loadMusic();

        void playBombEffect();

        void playOpenCellEffect();

        void playFlagEffect();

        void playOpeningTheme();

        void playWinTheme();

        void playLoseTheme();

        void stopMusic();

        void free();
    private:
        Mix_Chunk* mBomb;
        Mix_Chunk* mOpen;
        Mix_Chunk* mFlag;
        Mix_Music* mTheme;
        Mix_Music* mWin;
        Mix_Music* mLose;

        int currentMusic;
};

#endif