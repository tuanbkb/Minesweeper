#ifndef BOARD_H
#define BOARD_H

#include "SDL.h"
#include "constant.h"
#include "LTexture.h"
#include "LevelSelect.h"
#include "LMusic.h"

#include <sstream>

extern LevelSelect gLevelSelect;
extern LMusic gMusic;

class Board{
    public:
        static const int CELL_SIZE = 30;
        static const int NUM_OF_COL = 20;
        static const int NUM_OF_ROW = 20;
        
        Board();

        bool loadTexture();

        void generateBoard();

        void renderBoard();

        void openCell(int row, int col);

        void placeFlag(int row, int col);

        void revealBomb();

        void handleEvent(SDL_Event& e);   

        int getBombRemaining();

        bool checkFlagPlaced();

        bool bombActivated();

        void free(); 
    private:
        int gBoard[NUM_OF_ROW][NUM_OF_COL];
        int gBoardShown[NUM_OF_ROW][NUM_OF_COL];

        int NUM_OF_BOMB;

        LTexture gNormal;
        LTexture gBomb;
        LTexture gNumber[MAX_NUMBER_IN_CELL];
        LTexture gFlag;
        LTexture gBombText;

        int bombRemaining;
        int flagPlaced;
        bool bombIsActivated;
};



#endif