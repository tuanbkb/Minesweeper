#ifndef CONSTANT_H
#define CONSTANT_H

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const int MAX_NUMBER_IN_CELL = 8;

const char GAME_TITLE[] = "Minesweeper!";

const int TOP_LEFT_BOARD_X = 341;
const int TOP_LEFT_BOARD_Y = 61;

const int NUM_OF_BOMB = 80;

const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 100;

enum GAME_STATE {
    MAIN_MENU,
    PLAYING,
    END_SCREEN,
};

enum CELL_STATE {
    FLAG = -1,
    NORMAL = 0,
    SHOWN_CELL = 1,
};

enum BUTTON_STATE {
    NORMAL,
    MOUSE_OVER,
};

#endif