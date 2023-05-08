#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <SDL.h>
#include "LTexture.h"
#include "LButton.h"
#include "constant.h"

class LevelSelect {
    public:
        LevelSelect();

        bool loadTexture();

        void handleEvent(SDL_Event& e);

        void renderLevelSelectScreen();

        int getDifficulty();

        void free();
    private:
        LTexture mLevelSelectTexture;
        LTexture mDifficulty[3];

        LButton mPlay;

        int mDifficultyShown;
};

#endif