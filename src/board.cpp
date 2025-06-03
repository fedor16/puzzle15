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
bool Board::moveTile(int tile) {
    int tileRow = -1, tileCol = -1;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (board[r][c] == tile) {
                tileRow = r;
                tileCol = c;
            }
        }
    }
    if (tileRow == -1) return false;

    if ((abs(tileRow - emptyPos.first) == 1 && tileCol == emptyPos.second) ||
        (abs(tileCol - emptyPos.second) == 1 && tileRow == emptyPos.first)) {
        std::swap(board[tileRow][tileCol], board[emptyPos.first][emptyPos.second]);
        emptyPos = {tileRow, tileCol};
        return true;
    }
    return false;
}

bool Board::isSolved() const {
    int expected = 1;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            if (r == 3 && c == 3) {
                if (board[r][c] != 0)
                    return false;
            } else {
                if (board[r][c] != expected)
                    return false;
                ++expected;
            }
        }
    }
    return true;
}

