#include "game.h"

bool init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not be initialize! SDL Error: " << SDL_GetError() << endl;
        success = false;
    }
    else {
        gWindow = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
            success = false;
        }
        else {
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL) {
                cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
                success = false;
            }
            else {
                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);

                int imgFlag = IMG_INIT_PNG;
                if (!IMG_Init(imgFlag) & imgFlag) {
                    cout << "SDL_image could not be initialized! SDL_image Error: " << IMG_GetError() << endl;
                    success = false;
                }

                if (!TTF_Init() == -1) {
                    cout << "SDL_ttf could not be initialized! SDL_ttf Error: " << TTF_GetError() << endl;
                    success = false;
                }

                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                    cout << "SDL_mixer could not be initialized! SDL_mixer Error: " << Mix_GetError() << endl;
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia() {
    bool success = true;

    if (!gBoard.loadTexture()) {
        cout << "Fail to load board texture!" << endl;
        success = false;
    }

    if (!gPlayButton.defineButton("media/play.png", "media/play1.png", (SCREEN_WIDTH - LONG_BUTTON_WIDTH)/2 + 1, (SCREEN_HEIGHT - LONG_BUTTON_HEIGHT)/2 + 1, LEVEL_SELECT)) {
        cout << "Fail to define play button!" << endl;
        success = false;
    }

    if (!gReplayButton.defineButton("media/replay.png", "media/replay1.png", (SCREEN_WIDTH - 3*LONG_BUTTON_WIDTH)/2 + 1, (SCREEN_HEIGHT - LONG_BUTTON_HEIGHT)/2 + 1, PLAYING)) {
        cout << "Fail to define replay button!" << endl;
        success = false;
    }

    if (!gMenuButton.defineButton("media/menu.png", "media/menu1.png", (SCREEN_WIDTH + LONG_BUTTON_WIDTH)/2 + 1, (SCREEN_HEIGHT - LONG_BUTTON_HEIGHT)/2 + 1, MAIN_MENU)) {
        cout << "Fail to define menu button!" << endl;
        success = false;
    }

    gFont = TTF_OpenFont("media/ITCKRIST.TTF", 45);
    if (gFont == NULL) {
        cout << "Fail to load font! SDL_ttf Error: " << TTF_GetError() << endl;
        success = false;
    }
    
    if (!gLevelSelect.loadTexture()) {
        cout << "Fail to load level select texture!" << endl;
        success = false;
    }
    
    if (!gClickToContinue.loadFromFile("media/clickToContinue.png")) {
        cout << "Fail to load clickToContinue texture!" << endl;
        success = false;
    }

    if (!gTitleScreen.loadFromFile("media/title.png")) {
        cout << "Fail to load title screen texture!" << endl;
        success = false;
    }

    if (!gLoseScreen.loadFromFile("media/lose.png")) {
        cout << "Fail to load lose screen texture!" << endl;
        success = false;
    }

    if (!gWinScreen.loadFromFile("media/win.png")) {
        cout << "Fail to load win screen texture!" << endl;
        success = false;
    }

    if (!gPauseButton.defineButton("media/pause.png", "media/pause1.png", SCREEN_WIDTH - SQUARE_BUTTON_SIZE - 15, 15, PAUSING)) {
        cout << "Fail to define pause button" << endl;
        success = false;
    }

    if (!gContinueButton.defineButton("media/continue.png", "media/continue1.png", (SCREEN_WIDTH - 3*LONG_BUTTON_WIDTH)/2 + 1, (SCREEN_HEIGHT - LONG_BUTTON_HEIGHT)/2 + 1, PLAYING)) {
        cout << "Fail to define continue button" << endl;
        success = false;
    }

    if (!gMusic.loadMusic()) {
        cout << "Fail to load music!" << endl;
        success = false;
    }

    return success;
}

void close() {
    gBoard.free();
    gPlayButton.free();
    gReplayButton.free();
    gMenuButton.free();
    gContinueButton.free();
    gPauseButton.free();
    gClickToContinue.free();
    gTitleScreen.free();
    gWinScreen.free();
    gLoseScreen.free();
    gLevelSelect.free();

    gMusic.free();

    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;

    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
}

void waitHalfSecond() {
    Uint32 startTick = SDL_GetTicks();
    while (SDL_GetTicks() - startTick < 500) {
    }
}