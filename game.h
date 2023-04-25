#ifndef GAME_H
#define GAME_H

#include "LTexture.h"
#include "constant.h"
#include "board.h"
#include "LButton.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

using namespace std;

extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;

extern Board gBoard;
extern LButton gPlayButton;
extern LButton gReplayButton;
extern LButton gMenuButton;

bool init();

bool loadMedia();

void close();

#endif
