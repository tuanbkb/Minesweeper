#ifndef CONSTANT_H
#define CONSTANT_H

#include <SDL.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int MAX_NUMBER_IN_CELL = 8;

const char GAME_TITLE[] = "Minesweeper!";

const int TOP_LEFT_BOARD_X = 341;
const int TOP_LEFT_BOARD_Y = 61;
const int BOARD_WIDTH = 600;
const int BOARD_HEIGHT = 600;

//const int NUM_OF_BOMB = 80;

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 100;

const SDL_Color TEXT_COLOR = {255 ,255 ,255};

const int LEFT_BUTTON_POS_X = 440;
const int LEFT_BUTTON_POS_Y = 330;
const int RIGHT_BUTTON_POS_X = 790;
const int RIGHT_BUTTON_POS_Y = 330;
const int LEFT_RIGHT_BUTTON_SIZE = 55;

enum GAME_STATE {
    MAIN_MENU,
    LEVEL_SELECT,
    PLAYING,
    PAUSING,
    REVEAL_BOMB,
    END_SCREEN,
};

enum CELL_STATE {
    FLAG = -1,
    NORMAL = 0,
    SHOWN_CELL = 1,
};

enum BUTTON_STATE {
    NO_MOUSE_OVER,
    MOUSE_OVER,
};

enum DIFFICULTY {
    EASY,
    MEDIUM,
    HARD,
};

#endif