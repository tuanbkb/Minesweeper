#include "board.h"

Board::Board() {
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            gBoard[i][j] = 0;
            gBoardShown[i][j] = 0;
        }
    }
}

bool Board::loadTexture() {
    bool success = true;

    if (!gNormal.loadFromFile("media/normal.png")) {
        cout << "Fail to load normal tile texture!" << endl;
        success = false;
    }
    
    if (!gNumber[0].loadFromFile("media/0.png")) {
        cout << "Fail to load 0 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[1].loadFromFile("media/1.png")) {
        cout << "Fail to load 1 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[2].loadFromFile("media/2.png")) {
        cout << "Fail to load 2 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[3].loadFromFile("media/3.png")) {
        cout << "Fail to load 3 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[4].loadFromFile("media/4.png")) {
        cout << "Fail to load 4 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[5].loadFromFile("media/5.png")) {
        cout << "Fail to load 5 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[6].loadFromFile("media/6.png")) {
        cout << "Fail to load 6 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[7].loadFromFile("media/7.png")) {
        cout << "Fail to load 7 tile texture!" << endl;
        success = false;
    }

    if (!gNumber[8].loadFromFile("media/8.png")) {
        cout << "Fail to load 8 tile texture!" << endl;
        success = false;
    }

    if (!gBomb.loadFromFile("media/bomb.png")) {
        cout << "Fail to load bomb tile texture!" << endl;
        success = false;
    }

    if (!gFlag.loadFromFile("media/flag.png")) {
        cout << "Fail to load flag tile texture!" << endl;
        success = false;
    }

    return success;
}

void Board::generateBoard() {
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            gBoard[i][j] = 0;
            gBoardShown[i][j] = 0;
        }
    }
    for (int i = 0; i < NUM_OF_BOMB; i++) {
        int x, y;
        do {
            x = rand() % NUM_OF_COL;
            y = rand() % NUM_OF_ROW;
        }
        while (gBoard[y][x] == -1);
        gBoard[y][x] = -1;
    }
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            if (gBoard[i][j] != -1) {
                int count = 0;
                if (i > 0              && gBoard[i - 1][j] == -1) count++;
                if (i < NUM_OF_ROW - 1 && gBoard[i + 1][j] == -1) count++;
                if (j > 0              && gBoard[i][j - 1] == -1) count++;
                if (j < NUM_OF_COL - 1 && gBoard[i][j + 1] == -1) count++;
                if (i > 0              && j > 0              && gBoard[i - 1][j - 1] == -1) count++;
                if (i > 0              && j < NUM_OF_COL - 1 && gBoard[i - 1][j + 1] == -1) count++;
                if (i < NUM_OF_ROW - 1 && j < NUM_OF_COL - 1 && gBoard[i + 1][j + 1] == -1) count++;
                if (i < NUM_OF_ROW - 1 && j > 0              && gBoard[i + 1][j - 1] == -1) count++;
                gBoard[i][j] = count;
            }
        }
    }
    bombRemaining = NUM_OF_BOMB;
    bombIsActivated = false;
}

void Board::renderBoard() {
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            if (gBoardShown[i][j] == NORMAL) {
                gNormal.render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
            }
            else if (gBoardShown[i][j] == SHOWN_CELL) {
                switch(gBoard[i][j]) {
                    case 0:
                        gNumber[0].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 1:
                        gNumber[1].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 2:
                        gNumber[2].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 3:
                        gNumber[3].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 4:
                        gNumber[4].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 5:
                        gNumber[5].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 6:
                        gNumber[6].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 7:
                        gNumber[7].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                    case 8:
                        gNumber[8].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                        break;
                }
            }
            else {
                gFlag.render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
            }
        }
    }
}

void Board::openCell(int row, int col) {
    if (gBoardShown[row][col] == 0) {
        gBoardShown[row][col] = 1;
        if (gBoard[row][col] == 0) {
            if (col > 0) openCell(row, col - 1); 
            if (col < 19) openCell(row, col + 1); 
            if (row > 0) openCell(row - 1, col); 
            if (row < 19) openCell(row + 1, col);
            if (col > 0 && row > 0 && gBoard[row - 1][col - 1] > 0) openCell(row - 1, col - 1);
            if (col > 0 && row < 19 && gBoard[row + 1][col - 1] > 0) openCell(row + 1, col - 1);
            if (col < 19 && row > 0 && gBoard[row - 1][col + 1] > 0) openCell(row - 1, col + 1);
            if (col < 19 && row < 19 && gBoard[row + 1][col + 1] > 0) openCell(row + 1, col + 1);
        }
        else if (gBoard[row][col] == -1) bombIsActivated = true;
    }
}

void Board::placeFlag(int row, int col) {
    if (gBoardShown[row][col] == 0) {
        gBoardShown[row][col] = -1;
        if (gBoard[row][col] == -1) bombRemaining--;
    }
    else if (gBoardShown[row][col] == -1) {
        gBoardShown[row][col] = 0;
        if (gBoard[row][col] == -1) bombRemaining++;
    }
}

void Board::revealBomb() {                          //Chinh la ham renderBoard nhung hien thi tat ca bomb
    for (int i = 0; i < NUM_OF_ROW; i++) {
        for (int j = 0; j < NUM_OF_COL; j++) {
            if (gBoard[i][j] != -1) {
                if (gBoardShown[i][j] == NORMAL) {
                    gNormal.render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                }
                else if (gBoardShown[i][j] == SHOWN_CELL) {
                    switch(gBoard[i][j]) {
                        case 0:
                            gNumber[0].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 1:
                            gNumber[1].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 2:
                            gNumber[2].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 3:
                            gNumber[3].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 4:
                            gNumber[4].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 5:
                            gNumber[5].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 6:
                            gNumber[6].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 7:
                            gNumber[7].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                        case 8:
                            gNumber[8].render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
                            break;
                    }
                }
            }
            else gBomb.render(TOP_LEFT_BOARD_X + CELL_SIZE*j, TOP_LEFT_BOARD_Y + CELL_SIZE*i);
        }
    }
}

void Board::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x = 0, y = 0;
        SDL_GetMouseState(&x, &y);
        int row = (y - TOP_LEFT_BOARD_Y + 1)/CELL_SIZE;
        int col = (x - TOP_LEFT_BOARD_X + 1)/CELL_SIZE;
        if (e.button.button == SDL_BUTTON_LEFT) {
            if (row >= 0 && row < NUM_OF_ROW && col >= 0 && col < NUM_OF_COL) openCell(row, col);
        }
        else if (e.button.button == SDL_BUTTON_RIGHT) {
            if (row >= 0 && row < NUM_OF_ROW && col >= 0 && col < NUM_OF_COL) placeFlag(row, col);
        }
    }
}

int Board::getBombRemaining() {
    return bombRemaining;
}

bool Board::bombActivated() {
    return bombIsActivated;
}

void Board::free() {
    gNormal.free();
    gBomb.free();
    for (int i = 0; i <= MAX_NUMBER_IN_CELL; i++) {
        gNumber[i].free();
    }
    gFlag.free();
}