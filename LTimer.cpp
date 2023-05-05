#include "LTimer.h"

LTimer::LTimer() {
    mStartTick = 0;
    mPauseTick = 0;

    mStarted = false;
    mPaused = false;
}

void LTimer::start() {
    mStartTick = SDL_GetTicks();
    mPauseTick = 0;

    mStarted = true;
    mPaused = false;
}

void LTimer::stop() {
    mStartTick = 0;
    mPauseTick = 0;

    mStarted = false;
    mPaused = false;
}

void LTimer::pause() {
    if (!mPaused && mStarted) {
        mPauseTick = SDL_GetTicks64() - mStartTick;
        mStartTick = 0;

        mPaused = true;
    }
}

void LTimer::unpause() {
    if (mPaused && mStarted) {
        mPauseTick = 0;
        mStartTick = SDL_GetTicks64() - mPauseTick;

        mPaused = false;
    }
}

Uint32 LTimer::getTicks() {
    Uint32 time = 0;

    if (mStarted) {
        if (mPaused) {
            time = mPauseTick;
        }
        else {
            time = SDL_GetTicks64() - mStartTick;
        }
    }

    return time;
}

void LTimer::render() {
    stringstream timeText;
    timeText << "Time: " << getTicks()/1000;
    if (mTimeTexture.loadFromRenderText(timeText.str().c_str(), TEXT_COLOR)) {
        mTimeTexture.render((TOP_LEFT_BOARD_X - 1 - mTimeTexture.getWidth())/2, (SCREEN_HEIGHT - mTimeTexture.getHeight())/2);
    }
}

bool LTimer::isPaused() {
    return mPaused;
}

bool LTimer::isStarted() {
    return mStarted;
}