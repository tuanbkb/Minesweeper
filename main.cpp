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

int gameState = PLAYING;

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
                        case PLAYING:
                            gBoard.handleEvent(e);
                            break;
                    }
                }
                SDL_SetRenderDrawColor(gRenderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(gRenderer);

                switch (gameState) {
                    case MAIN_MENU:
                        break;
                    case PLAYING:
                        if (!boardIsGenerated) {
                            gBoard.generateBoard();
                            boardIsGenerated = true;
                        }
                        else {
                            gBoard.renderBoard();
                        }
                        if (gBoard.getBombRemaining() == 0 || gBoard.bombActivated()) gameState = END_SCREEN;
                        break;
                    case END_SCREEN:
                        break;
                }
                

                SDL_RenderPresent(gRenderer);
            }
        }
    }
    close();

    return 0;
}