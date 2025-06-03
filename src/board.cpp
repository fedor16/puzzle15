#include "board.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

Board::Board() {
    std::srand(std::time(0));
    initializeBoard();
}

void Board::initializeBoard() {
    int num = 1;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (num < 16) {
                board[r][c] = num++;
            } else {
                board[r][c] = 0;
                emptyPos = {r, c};
            }
        }
    }
}

void Board::display() const {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (board[r][c] == 0)
                std::cout << "   ";
            else
                std::cout << board[r][c] << "\t";
        }
        std::cout << std::endl;
    }
}
