#include "LevelSelect.h"

LevelSelect::LevelSelect() {
    mDifficultyShown = EASY;
}

bool LevelSelect::loadTexture() {
    bool success = true;
    if (!mPlay.defineButton("media/play.png", "media/play1.png", (SCREEN_WIDTH - BUTTON_WIDTH)/2, 500, PLAYING)) success = false;
    if (!mLevelSelectTexture.loadFromFile("media/levelselect.png")) success = false;
    if (!mDifficulty[EASY].loadFromRenderText("Easy", TEXT_COLOR)) success = false;
    if (!mDifficulty[MEDIUM].loadFromRenderText("Medium", TEXT_COLOR)) success = false;
    if (!mDifficulty[HARD].loadFromRenderText("Hard", TEXT_COLOR)) success = false;
    return success;
}

void LevelSelect::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool insideLeft = true;
        bool insideRight = true;
        if (x < LEFT_BUTTON_POS_X || x > LEFT_BUTTON_POS_X + LEFT_RIGHT_BUTTON_SIZE || y < LEFT_BUTTON_POS_Y || y > LEFT_BUTTON_POS_Y + LEFT_RIGHT_BUTTON_SIZE) insideLeft = false;
        if (x < RIGHT_BUTTON_POS_X || x > RIGHT_BUTTON_POS_X + LEFT_RIGHT_BUTTON_SIZE || y < RIGHT_BUTTON_POS_Y || y > RIGHT_BUTTON_POS_Y + LEFT_RIGHT_BUTTON_SIZE) insideRight = false;
        if (insideLeft) {
            mDifficultyShown--;
            if (mDifficultyShown < EASY) mDifficultyShown += 3;
        }
        if (insideRight) {
            mDifficultyShown++;
            if (mDifficultyShown > HARD) mDifficultyShown -= 3;
        }
    }
    mPlay.handleEvent(e);
}

void LevelSelect::renderLevelSelectScreen() {
    mLevelSelectTexture.render(0, 0);
    mDifficulty[mDifficultyShown].render(LEFT_BUTTON_POS_X + LEFT_RIGHT_BUTTON_SIZE + (RIGHT_BUTTON_POS_X - LEFT_BUTTON_POS_X - LEFT_RIGHT_BUTTON_SIZE - mDifficulty[mDifficultyShown].getWidth())/2, LEFT_BUTTON_POS_Y + (LEFT_RIGHT_BUTTON_SIZE - mDifficulty[mDifficultyShown].getHeight())/2);
    mPlay.render();
}

int LevelSelect::getDifficulty() {
    return mDifficultyShown;
}

void LevelSelect::free() {
    mLevelSelectTexture.free();
    mDifficulty[EASY].free();
    mDifficulty[MEDIUM].free();
    mDifficulty[HARD].free();
    mPlay.free();
}