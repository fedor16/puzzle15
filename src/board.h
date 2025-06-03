#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    void shuffle();          
    void display() const;    
    bool moveTile(int tile);  
    bool isSolved() const;    

private:
    int board[4][4];
    std::pair<int, int> emptyPos;
    void initializeBoard();  
};

#endif // BOARD_H

