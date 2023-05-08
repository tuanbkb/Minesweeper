#include "game.h"
#include "board.h"
#include "LButton.h"
#include "LTimer.h"
#include "LevelSelect.h"
#include "LMusic.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont = NULL;

Board gBoard;
LButton gPlayButton;
LButton gReplayButton;
LButton gMenuButton;
LButton gPauseButton;
LButton gContinueButton;
LTimer gTimer;
LevelSelect gLevelSelect;

LTexture gClickToContinue;
LTexture gTitleScreen;
LTexture gLoseScreen;
LTexture gWinScreen;

LMusic gMusic;

int gameState = MAIN_MENU;

int main(int argc, char** args) {
    srand(time(0));
    if (!init()) {
        cout << "Fail to initialize!" << endl;
    }
    else {
        if (!loadMedia()) {
            cout << "Fail to load media!" << endl;
        }
        else {
            bool boardIsGenerated = false;

            bool quit = false;

            SDL_Event e;

            while (!quit) {
                if (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                    switch (gameState) {
                        case MAIN_MENU:
                            gPlayButton.handleEvent(e);
                            break;
                        case LEVEL_SELECT:
                            gLevelSelect.handleEvent(e);
                            break;
                        case PLAYING:
                            gBoard.handleEvent(e);
                            gPauseButton.handleEvent(e);
                            break;
                        case PAUSING:
                            gContinueButton.handleEvent(e);
                            gMenuButton.handleEvent(e);
                            break;
                        case REVEAL_BOMB:
                            if (e.type == SDL_MOUSEBUTTONDOWN) gameState = END_SCREEN;
                        case END_SCREEN:
                            gReplayButton.handleEvent(e);
                            gMenuButton.handleEvent(e);
                            break;
                    }
                }
                SDL_SetRenderDrawColor(gRenderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(gRenderer);

                switch (gameState) {
                    case MAIN_MENU:
                        boardIsGenerated = false;
                        if (gTimer.isStarted()) gTimer.stop();
                        gTitleScreen.render(0, 0);
                        gPlayButton.render();
                        gMusic.playOpeningTheme();
                        break;
                    case LEVEL_SELECT:
                        gLevelSelect.renderLevelSelectScreen();
                        break;
                    case PLAYING:
                        if (!boardIsGenerated) {
                            gBoard.generateBoard();
                            boardIsGenerated = true;
                            gTimer.stop();
                        }
                        else {
                            if (!gTimer.isStarted()) gTimer.start();
                            else if (gTimer.isPaused()) gTimer.unpause();
                            gBoard.renderBoard();
                            gTimer.render((TOP_LEFT_BOARD_X - 1 - gTimer.getTextureWidth())/2, 250);
                            gPauseButton.render();
                            gMusic.stopMusic();
                        }
                        if (gBoard.getBombRemaining() == 0 && gBoard.checkFlagPlaced()) {
                            waitHalfSecond();
                            gameState = END_SCREEN;
                            gTimer.pause();
                            boardIsGenerated = false;
                        }
                        else if (gBoard.bombActivated()) {
                            gameState = REVEAL_BOMB;
                            gTimer.pause();
                            boardIsGenerated = false;
                        }
                        break;
                    case PAUSING:
                        if (!gTimer.isPaused()) gTimer.pause();
                        gContinueButton.render();
                        gMenuButton.render();
                        break;
                    case REVEAL_BOMB:
                        gBoard.revealBomb();
                        gClickToContinue.render(SCREEN_WIDTH - gClickToContinue.getWidth(), (SCREEN_HEIGHT - gClickToContinue.getHeight())/2);
                        gTimer.render((TOP_LEFT_BOARD_X - 1 - gTimer.getTextureWidth())/2, 250);
                        break;
                    case END_SCREEN:
                        if (gBoard.bombActivated()) {gLoseScreen.render(0, 0); gMusic.playLoseTheme();}
                        else {gWinScreen.render(0, 0); gMusic.playWinTheme(); gTimer.render((SCREEN_WIDTH - gTimer.getTextureWidth())/2, 220);}
                        gReplayButton.render();
                        gMenuButton.render();
                        break;
                }
            
                SDL_RenderPresent(gRenderer);
            }
        }
    }
    close();

    return 0;
}