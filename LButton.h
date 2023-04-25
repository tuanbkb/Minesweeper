#ifndef LBUTTON_H
#define LBUTTON_H

#include "LTexture.h"
#include "constant.h"

#include <SDL.h>

extern int gameState;

class LButton {
    public:
        static const int BUTTON_WIDTH = 200;
        static const int BUTTON_HEIGHT = 100;

        LButton();

        bool defineButton(string path1, string path2, int x, int y, int clickState);

        void handleEvent(SDL_Event& e);

        void render();

        void free();
    private:
        LTexture currentButtonTexture;
        LTexture BUTTON_TEXTURE[2];

        int clickPurpose;

        int mPosX, mPosY;
};

#endif