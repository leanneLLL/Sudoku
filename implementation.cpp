#include<iostream>
#include"gameFile.h"
#include "implementation.hpp"
using namespace std;
//打出游戏板
void SUDOKU::printBoard(int boardArray[][9]){    //打出游戏面板的数组
    cout<<"══════════════════════════"<<endl;
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(boardArray[x][y]==0){   //求的未知数 打出星号键
                cout<<"*  ";}
            else{ cout<<boardArray[x][y]<<"  ";}
        }
        cout<<endl;}
    cout<<"══════════════════════════"<<endl;
}

//游戏进程
int SUDOKU::playGame(int boardArray[9][9],int answer[9][9]){
    int score=100;
    int error=0;
    int row=0;
    int column=0;
    int number;
    //int time=0;
    printBoard(boardArray);
    while(1){
        cout<<endl;
        //while(time <=count ){
        while(true){
            cout<<" ◎ Enter ROW                ➤";
            cin>>row;
            cout<<" ◎ Enter COLUMN             ➤";
            cin>>column;
            if (boardArray[row-1][column-1] != 0){
                cout<<endl;
                cout<<"           ╭-----------------------------------╮"<<endl;
                cout<<"           |        ×  Invalid Entry  ×        |"<<endl;
                cout<<"           |          Try another spot         |"<<endl;
                cout<<"           ╰-----------------------------------╯"<<endl<<endl;continue;
                
            }
            else if((row<0||row>9)&&(column<0 ||column>9)){
                cout<<endl;
                cout<<"           ╭-----------------------------------╮"<<endl;
                cout<<"           |        ×  Invalid Entry  ×        |"<<endl;
                cout<<"           |          Try another spot         |"<<endl;
                cout<<"           ╰-----------------------------------╯"<<endl<<endl;;continue;}
            break;
        }
        cout<<" ◎ Enter NUMBER             ➤";
        cin>>number;
        count=count+1;boardArray[row-1][column-1]=number;
        if(boardArray[row-1][column-1]==answer[row-1][column-1]){
            cout<<endl<<"  ✓ CORRECT                    SCORE 【"<<score<<"】 ERROR 【"<<error<<"】"<<endl<<endl<<endl;
            printBoard(boardArray);}
        else{
            score=score-5;error=error+1;boardArray[row-1][column-1]=0;
            cout<<endl<<"  ✗ WRONG                    SCORE 【"<<score<<"】 ERROR 【"<<error<<"】"<<endl<<endl<<endl;;
            printBoard(boardArray);}}
    if(score==100){
        cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
        cout<<"║= = = = = = = = = = = = END OF THE GAME = = = = = = = = = = = =║"<<endl;
        cout<<"║              Excellent Player, Should Try Next Level          ║"<<endl;
        cout<<"╚═══════════════════════════════════════════════════════════════╝"<<endl;return 0;}
    else if(score>=80 && score<100){
        cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
        cout<<"║= = = = = = = = = = = = END OF THE GAME = = = = = = = = = = = =║"<<endl;
        cout<<"║              Good Player, Keep Practicing This Level          ║"<<endl;
        cout<<"╚═══════════════════════════════════════════════════════════════╝"<<endl;return 0;}
    else if(score>=60&&score<80){
        cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
        cout<<"║= = = = = = = = = = = = END OF THE GAME = = = = = = = = = = = =║"<<endl;
        cout<<"║      OK Player...Keep Practicing This Level If You Dare       ║"<<endl;
        cout<<"╚═══════════════════════════════════════════════════════════════╝"<<endl;return 0;}
    else if(score>=40&&score<60){
        cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
        cout<<"║= = = = = = = = = = = = END OF THE GAME = = = = = = = = = = = =║"<<endl;
        cout<<"║               Well, Suggest Try A Easier Level                ║"<<endl;
        cout<<"╚═══════════════════════════════════════════════════════════════╝"<<endl;return 0;}
    else{
        cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
        cout<<"║= = = = = = = = = = = = END OF THE GAME = = = = = = = = = = = =║"<<endl;
        cout<<"║         Please Watch More Online Videos On How To Play         ║"<<endl;
        cout<<"╚═══════════════════════════════════════════════════════════════╝"<<endl;return 0;}
}//}
//游戏总进程
int SUDOKU::startGame(){
    SUDOKU game;
    char option;
    int level;
    srand((unsigned)time(NULL));
    int randomChoose=rand()%10+1;
    cout<<"╔═══════════════════════════════════════════════════════════════╗"<<endl;
    cout<<"║= = = = = = = = = = WELCOME TO SUDOKU GAME = = = = = = = = =  =║"<<endl;
    cout<<"║                                                               ║"<<endl;
    cout<<"║  ▶Please Select          S - start game                       ║"<<endl;
    cout<<"║                          0 - quit game                        ║"<<endl;
    cout<<"╚═══════════════════════════════════════════════════════════════╝"<<" ➤ ";
    while(true){cin>>option;
        if(option=='S'){break;}
        else if(option=='0'){
            cout<<endl;
            cout<<"           ╭-----------------------------------╮"<<endl;
            cout<<"           |      ☺ See You Next Time          |"<<endl;
            cout<<"           ╰-----------------------------------╯    ";
            cout<<endl<<endl;
            return 0;}
        else{
            cout<<"           ╭-----------------------------------╮"<<endl;
            cout<<"           |        ×  Invalid Entry  ×        |"<<endl;
            cout<<"           | ▶Please Select    S - start game  |"<<endl;
            cout<<"           |                   0 - quit game   |"<<endl;
            cout<<"           ╰-----------------------------------╯                  ➤ ";}
    }
    cout<<endl;
    cout<<"      ► Level 1 Very Esay      ► Level 2 Esay"<<endl;
    cout<<"      ► Level 3 Medium         ► Level 4 Hard                    ➤ ";
    while(true){cin>>level;
        if(level == 1||level == 2||level == 3||level ==4){
            switch(level){
                case 1:
                    cout<<endl<<"               ----- MODE ♘ Very Esay -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1VeryEsay,sudoku1);break;
                        case 2:game.playGame(sudoku2VeryEsay,sudoku2);break;
                        case 3:game.playGame(sudoku3VeryEsay,sudoku3);break;
                        case 4:game.playGame(sudoku4VeryEsay,sudoku4);break;
                        case 5:game.playGame(sudoku5VeryEsay,sudoku5);break;
                        case 6:game.playGame(sudoku6VeryEasy,sudoku6);break;
                        case 7:game.playGame(sudoku7VeryEsay,sudoku7);break;
                        case 8:game.playGame(sudoku8VeryEsay,sudoku8);break;
                        case 9:game.playGame(sudoku9VeryEasy,sudoku9);break;
                        case 10:game.playGame(sudoku10VeryEsay,sudoku10);break;}
                case 2:
                    cout<<endl<<"               ----- MODE ♖  Esay -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Esay,sudoku1);break;
                        case 2:game.playGame(sudoku2Esay,sudoku2);break;
                        case 3:game.playGame(sudoku3Esay,sudoku3);break;
                        case 4:game.playGame(sudoku4Esay,sudoku4);break;
                        case 5:game.playGame(sudoku5Esay,sudoku5);break;
                        case 6:game.playGame(sudoku6Easy,sudoku6);break;
                        case 7:game.playGame(sudoku7Esay,sudoku7);break;
                        case 8:game.playGame(sudoku8Esay,sudoku8);break;
                        case 9:game.playGame(sudoku9Easy,sudoku9);break;
                        case 10:game.playGame(sudoku10Esay,sudoku10);break;}
                case 3:
                    cout<<endl<<"               ----- MODE ♔  Medium -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Midium,sudoku1);break;
                        case 2:game.playGame(sudoku2Medium,sudoku2);break;
                        case 3:game.playGame(sudoku3Medium,sudoku3);break;
                        case 4:game.playGame(sudoku4Medium,sudoku4);break;
                        case 5:game.playGame(sudoku5Medium,sudoku5);break;
                        case 6:game.playGame(sudoku6Medium,sudoku6);break;
                        case 7:game.playGame(sudoku7Medium,sudoku7);break;
                        case 8:game.playGame(sudoku8Medium,sudoku8);break;
                        case 9:game.playGame(sudoku9Medium,sudoku9);break;
                        case 10:game.playGame(sudoku10Medium,sudoku10);break;}
                case 4:
                    cout<<endl<<"               ----- MODE ♕  Hard -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Hard,sudoku1);break;
                        case 2:game.playGame(sudoku2Hard,sudoku2);break;
                        case 3:game.playGame(sudoku3Hard,sudoku3);break;
                        case 4:game.playGame(sudoku4Hard,sudoku4);break;
                        case 5:game.playGame(sudoku5Hard,sudoku5);break;
                        case 6:game.playGame(sudoku6Hard,sudoku6);break;
                        case 7:game.playGame(sudoku7Hard,sudoku7);break;
                        case 8:game.playGame(sudoku8Hard,sudoku8);break;
                        case 9:game.playGame(sudoku9Hard,sudoku9);break;
                        case 10:game.playGame(sudoku10Hard,sudoku10);break;}
            }}   //先结束switch 在结束if
        else if(level==0){cout<<endl;
            cout<<"           ╭-------------------------------╮"<<endl;
            cout<<"           |      ☺ See You Next Time      |"<<endl;
            cout<<"           ╰-------------------------------╯    ";
            cout<<endl<<endl;
            return 0;}
        else {
            cout<<endl;
            cout<<"           ╭------------------------------╮"<<endl;
            cout<<"           |     ×  Invalid Entry  ×      |"<<endl;
            cout<<"           ╰------------------------------╯"<<endl;
            cout<<endl;
            cout<<"      ► Level 1 Very Esay      ► Level 2 Esay   "<<endl;
            cout<<"      ► Level 3 Medium         ► Level 4 Hard                    ➤";}
        
    }
}
