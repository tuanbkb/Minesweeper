#include "game.h"
#include "board.h"
#include "LButton.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

TTF_Font* gFont;

Board gBoard;
LButton gPlayButton;
LButton gReplayButton;
LButton gMenuButton;

LTexture gClickToContinue;

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
                        case PLAYING:
                            gBoard.handleEvent(e);
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
                        gPlayButton.render();
                        break;
                    case PLAYING:
                        if (!boardIsGenerated) {
                            gBoard.generateBoard();
                            boardIsGenerated = true;
                        }
                        else {
                            gBoard.renderBoard();
                        }
                        if (gBoard.getBombRemaining() == 0) {
                            waitHalfSecond();
                            gameState = END_SCREEN;
                            boardIsGenerated = false;
                        }
                        else if (gBoard.bombActivated()) {
                            gameState = REVEAL_BOMB;
                            boardIsGenerated = false;
                        }
                        break;
                    case REVEAL_BOMB:
                        gBoard.revealBomb();
                        gClickToContinue.render(SCREEN_WIDTH - gClickToContinue.getWidth(), (SCREEN_HEIGHT - gClickToContinue.getHeight())/2);
                        break;
                    case END_SCREEN:
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