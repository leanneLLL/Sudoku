#ifndef sudoku_hpp
#define sudoku_hpp
#include <stdio.h>
class SUDOKU{
private:
    int boardArray;
    int ansewr;
public:
    void checkAnswer();
    void playGame(int array[9][9],int answer[9][9]);
    void choseLevel();
    void printBoard(int boardArray[9][9]);
    void startGame();
};
#endif /* sudoku_hpp */
