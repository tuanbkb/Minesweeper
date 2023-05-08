#include "LButton.h"

LButton::LButton() {
    mPosX = 0;
    mPosY = 0;

    clickPurpose = 0;
}

bool LButton::defineButton(string path1, string path2, int x, int y, int clickState) {
    bool success = true;
    if (!BUTTON_TEXTURE[NO_MOUSE_OVER].loadFromFile(path1)) {
        success = false;
    }
    if (!BUTTON_TEXTURE[MOUSE_OVER].loadFromFile(path2)) {
        success = false;
    }

    mPosX = x;
    mPosY = y;

    currentButtonTexture = BUTTON_TEXTURE[NO_MOUSE_OVER];

    clickPurpose = clickState;
    return success;
}

void LButton::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;
        if (x < mPosX || x > mPosX + LONG_BUTTON_WIDTH || y < mPosY || y > mPosY + LONG_BUTTON_HEIGHT) inside = false;
        if (inside) {
            if (e.type == SDL_MOUSEMOTION) currentButtonTexture = BUTTON_TEXTURE[MOUSE_OVER];
            else if (e.type == SDL_MOUSEBUTTONDOWN) gameState = clickPurpose;
        }
        else currentButtonTexture = BUTTON_TEXTURE[NO_MOUSE_OVER];
    }
}

void LButton::render() {
    currentButtonTexture.render(mPosX, mPosY);
}

void LButton::free() {
    currentButtonTexture.free();
    BUTTON_TEXTURE[NO_MOUSE_OVER].free();
    BUTTON_TEXTURE[MOUSE_OVER].free();
}