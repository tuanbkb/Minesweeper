#ifndef LTIMER_H
#define LTIMER_H

#include "LTexture.h"
#include "constant.h"
#include <sstream>

#include <SDL.h>

class LTimer {
    public:
        LTimer();

        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 getTicks();

        void render(int x, int y);

        int getTextureWidth();
        bool isStarted();
        bool isPaused();
    private:
        Uint32 mStartTick;
        Uint32 mPauseTick;

        bool mPaused;
        bool mStarted;

        LTexture mTimeTexture;
};

#endif