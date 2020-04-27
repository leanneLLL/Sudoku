#include "sudoku.hpp"
#include "gameFile.h"
#include<iostream>
using namespace std;

//打出游戏板
void SUDOKU::printBoard(int boardArray[9][9]){    //打出游戏面板的数组
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(boardArray[x][y]==0){   //求的未知数 打出星号键
                cout<<" * ";}
            cout<<boardArray[x][y];   //其他的直接出数
        }}}
//检查答案
//void checkAnswer(int boardArray[9][9],int answer){   //检查答案正确
//    for(int x=0;x<9;x++){
//        for(int y=0;y<0;y++){
//            if(boardArray[x][y] != answer[x][y]){
//                cout<<"Wrong";}}}}
//游戏进程
void SUDOKU::playGame(int board[9][9],int answer[9][9]){
    int score=100;
    int error=0;
    int row, column;
    int number;
    //printBoard(boardArray);
    while(1){
        while(true){cout<<"Enter row and column"<<endl;cin>>row>>column;
            if(boardArray[row][column] ！= 0){cout<<"Number already exist, try another spot";}
            else if((0>row||row>9)&&(column<0 ||column>9)){cout<<"Invalid spot, try another spot";}
        }
        cout<<"Enter the number";
        cin>>number;
        board[row][column]=number;
        if(board[row][column]==answer[row][column]){cout<<"Correct";printBoard(boardArray);
        }
        else{cout<<"Wrong";score=score-5;error=error+1;printBoard(boardArray);
        }
    }
}
//游戏总进程
void SUDOKU::startGame(){
    SUDOKU game;
    char option;
    char level;
    srand((unsigned)time(NULL));
    int randomChoose=rand()%10+1;
    cout<<"=== SUDOKU GAME==="<<endl;
    cout<<"Please Select"<<endl;
    cout<<" S   start game     Q   quit game"<<endl;
    while(true){cin>>option;
        if(option=='S'){break;}
        else if(option=='Q'){cout<<"See you next time"<<endl;return 0;}
        else{cout<<"Please Select"<<endl;cout<<" S   start game     Q   quit game"<<endl;}
    }
    cout<<"Have four levels"<<endl;
    cout<<"1-very easy   2-esay   3-medium   4-hard   Q-quit"<<endl;
    while(true){0cin>>level;
        while(level!='1'&&level!='2'&&level!='3'&&level!='4'&&level!='Q'){
            switch(level){
                case 'Q':return 0;
                case '1':
                    cout<<"Very Esay"<<endl;
                    switch(randomChoose){
                        case 1:cout<<" board 1 very esay";game.playGame(sudoku1VeryEsay,sudoku1);break;
                        case 2:cout<<" board 2 very esay";game.playGame(sudoku2VeryEsay,sudoku2);break;
                        case 3:cout<<" board 3 very esay";game.playGame(sudoku3VeryEsay,sudoku3);break;
                        case 4:cout<<" board 4 very esay";game.playGame(sudoku4VeryEsay,sudoku4);break;
                        case 5:cout<<" board 5 very esay";game.playGame(sudoku5VeryEsay,sudoku5);break;
                        case 6:cout<<" board 6 very esay";game.playGame(sudoku6VeryEsay,sudoku6);break;
                        case 7:cout<<" board 7 very esay";game.playGame(sudoku7VeryEsay,sudoku7);break;
                        case 8:cout<<" board 8 very esay";game.playGame(sudoku8VeryEsay,sudoku8);break;
                        case 9:cout<<" board 9 very esay";game.playGame(sudoku9VeryEsay,sudoku9);break;
                        case 10:cout<<" board 10 very esay";game.playGame(sudoku10VeryEsay,sudoku10);break;}
                case '2':
                    cout<<"Esay"<<endl;
                    switch(randomChoose){
                        case 1:cout<<" board 1 esay";game.playGame(sudoku1Esay,sudoku1);break;
                        case 2:cout<<" board 2 esay";game.playGame(sudoku2Esay,sudoku2);break;
                        case 3:cout<<" board 3 esay";game.playGame(sudoku3Esay,sudoku3);break;
                        case 4:cout<<" board 4 esay";game.playGame(sudoku4Esay,sudoku4);break;
                        case 5:cout<<" board 5 esay";game.playGame(sudoku5Esay,sudoku5);break;
                        case 6:cout<<" board 6 esay";game.playGame(sudoku6Esay,sudoku6);break;
                        case 7:cout<<" board 7 esay";game.playGame(sudoku7Esay,sudoku7);break;
                        case 8:cout<<" board 8 esay";game.playGame(sudoku8Esay,sudoku8);break;
                        case 9:cout<<" board 9 esay";game.playGame(sudoku9Esay,sudoku9);break;
                        case 10:cout<<" board 10 esay";game.playGame(sudoku10Esay,sudoku10);break;}
                case '3':
                    cout<<"Medium"<<endl;
                    switch(randomChoose){
                        case 1:cout<<" board 1 medium";game.playGame(sudoku1Medium,sudoku1);break;
                        case 2:cout<<" board 2 medium";game.playGame(sudoku2Medium,sudoku2);break;
                        case 3:cout<<" board 3 medium";game.playGame(sudoku3Medium,sudoku3);break;
                        case 4:cout<<" board 4 medium";game.playGame(sudoku4Medium,sudoku4);break;
                        case 5:cout<<" board 5 medium";game.playGame(sudoku5Medium,sudoku5);break;
                        case 6:cout<<" board 6 medium";game.playGame(sudoku6Medium,sudoku6);break;
                        case 7:cout<<" board 7 medium";game.playGame(sudoku7Medium,sudoku7);break;
                        case 8:cout<<" board 8 medium";game.playGame(sudoku8Medium,sudoku8);break;
                        case 9:cout<<" board 9 medium";game.playGame(sudoku9Medium,sudoku9);break;
                        case 10:cout<<" board 10 medium";game.playGame(sudoku10Medium,sudoku10);break;}
                case '4':
                    cout<<"Hard"<<endl;
                    switch(randomChoose){
                        case 1:cout<<" board 1 hard";game.playGame(sudoku1Hard,sudoku1);break;
                        case 2:cout<<" board 2 hard";game.playGame(sudoku2Hard,sudoku2);break;
                        case 3:cout<<" board 3 hard";game.playGame(sudoku3Hard,sudoku3);break;
                        case 4:cout<<" board 4 hard";game.playGame(sudoku4Hard,sudoku4);break;
                        case 5:cout<<" board 5 hard";game.playGame(sudoku5Hard,sudoku5);break;
                        case 6:cout<<" board 6 hard";game.playGame(sudoku6Hard,sudoku6);break;
                        case 7:cout<<" board 7 hard";game.playGame(sudoku7Hard,sudoku7);break;
                        case 8:cout<<" board 8 hard";game.playGame(sudoku8Hard,sudoku8);break;
                        case 9:cout<<" board 9 hard";game.playGame(sudoku9Hard,sudoku9);break;
                        case 10:cout<<" board 10 hard";game.playGame(sudoku10Hard,sudoku10);break;}
                  
            }}
        else{cout<<"1-very easy   2-esay   3-medium   4-hard   Q-quit"<<endl;cin>>level;}
    }}

