#ifndef implementation_hpp
#define implementation_hpp
#include"gameFile.h"
#include <stdio.h>
class SUDOKU{
private:
    int boardArray[9][9];
    int answer[9][9];
    int count=0;
public:
    void printBoard(int boardArray[9][9]);
    int playGame(int array[9][9],int answer[9][9]);
    int startGame();
};
#endif /* implementation_hpp */
