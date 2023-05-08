#include "LMusic.h"
#include "constant.h"

LMusic::LMusic() {
    mOpen = NULL;
    mBomb = NULL;
    mTheme = NULL;
    mWin = NULL;
    mLose = NULL;

    currentMusic = MENU;
}

bool LMusic::loadMusic() {
    bool success = true;

    mOpen = Mix_LoadWAV("media/click.wav");
    if (mOpen == NULL) {
        std::cout << "Fail to load click effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    mBomb = Mix_LoadWAV("media/bomb.wav");
    if (mBomb == NULL) {
        std::cout << "Fail to load bomb effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    mFlag = Mix_LoadWAV("media/flag.wav");
    if (mFlag == NULL) {
        std::cout << "Fail to load flag effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    mTheme = Mix_LoadMUS("media/maintheme.mp3");
    if (mTheme == NULL) {
        std::cout << "Fail to load menu music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    mWin = Mix_LoadMUS("media/win.mp3");
    if (mWin == NULL) {
        std::cout << "Fail to load win music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    mLose = Mix_LoadMUS("media/lose.mp3");
    if (mLose == NULL) {
        std::cout << "Fail to load lose music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        success = false;
    }

    return success;
}

void LMusic::playOpeningTheme() {
    if (Mix_PlayingMusic() == 0 || currentMusic != MENU) {
        Mix_PlayMusic(mTheme, -1);
        currentMusic = MENU;
    }
}

void LMusic::playWinTheme() {
    if (Mix_PlayingMusic() == 0 || currentMusic != WIN) {
        Mix_PlayMusic(mWin, -1);
        currentMusic = WIN;
    }
}

void LMusic::playLoseTheme() {
    if (Mix_PlayingMusic() == 0 || currentMusic != LOSE) {
        Mix_PlayMusic(mLose, -1);
        currentMusic = LOSE;
    }
}

void LMusic::playOpenCellEffect() {
    Mix_PlayChannel(-1, mOpen, 0);
}

void LMusic::playBombEffect() {
    Mix_PlayChannel(-1, mBomb, 0);
}

void LMusic::playFlagEffect() {
    Mix_PlayChannel(-1, mFlag, 0);
}

void LMusic::stopMusic() {
    if (Mix_PlayingMusic() == 1) Mix_HaltMusic();
}

void LMusic::free() {
    Mix_FreeChunk(mOpen);
    Mix_FreeChunk(mBomb);
    Mix_FreeChunk(mFlag);
    Mix_FreeMusic(mTheme);
    Mix_FreeMusic(mWin);
    Mix_FreeMusic(mLose);
    mOpen = NULL;
    mFlag = NULL;
    mBomb = NULL;
    mTheme = NULL;
    mWin = NULL;
    mLose = NULL;
}