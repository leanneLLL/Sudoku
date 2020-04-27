#include<iostream>
#include<string>
#include<time.h>
#include"gameFile.h"
using namespace std;

class SUDOKU{
private:
    int boardArray[9][9];
    int answer[9][9];
    int count=0;   //level & finish game
public:
    int selectLevel();
    void printBoard(int boardArray[9][9]);
    int playGame(int array[9][9],int answer[9][9]);
    int startGame();
    bool checkFinish(int boardQuestion[9][9],int baordAnswer[9][9]);
};


//int SUDOKU::selectLevel(){
//    char level;
//    cout<<"      > Level 1 Very Esay      > Level 2 Esay    > Level 3 Medium         > Level 4 Hard       >";
//    cin>>level;
 //   while(cin>>level){
 //       switch(level){
                //level 1 return case 1
                //level 2 return case 2;
//        }
//    } error not solved
//}
//print our the game in two dimension array with blank*
void SUDOKU::printBoard(int boardArray[][9]){    //打出游戏面板的数组
    cout<<"--------------------------"<<endl;
    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            if(boardArray[x][y]==0){   //求的未知数 打出星号键
                cout<<"*  ";}
            else{ cout<<boardArray[x][y]<<"  ";}
        }
        cout<<endl;}
    cout<<"--------------------------"<<endl;
}


//游戏进程
int SUDOKU::playGame(int boardArray[9][9],int answer[9][9]){
    int score=100;
    int error=0;
    int row=0;
    int column=0;
    printBoard(boardArray);
    while(!checkFinish(boardArray,answer )){ //check to make sure if the user finished the question. GROUP WORK OF TWO!
        cout<<endl;
        cout<<" ～ Enter ROW                ·>";
        cin>>row;
        cout<<" ～ Enter COLUMN             ·>";
        cin>>column;
        if (boardArray[row-1][column-1] != 0){
            cout<<endl;
            cout<<"                   !  Invalid Entry  !        "<<endl;
            cout<<"           >Please Select    S - start game  "<<endl;
            cout<<"                             0 - quit game                        > "<<endl;continue;}
        else if((row<0||row>9)&&(column<0 ||column>9)){
            cout<<endl;
            cout<<"                   !  Invalid Entry  !        "<<endl;
            cout<<"           >Please Select    S - start game  "<<endl;
            cout<<"                             0 - quit game                        > "<<endl;continue;}
        else {
            int number;
            cout<<" ～ Enter NUMBER             >";
            cin>>number;
            boardArray[row-1][column-1]=number;
            if(boardArray[row-1][column-1]==answer[row-1][column-1]){
                cout<<endl<<"   :) CORRECT                    SCORE 【"<<score<<"】 ERROR 【"<<error<<"】"<<endl<<endl<<endl;
                printBoard(boardArray);}
            else{
                score=score-5;error=error+1;boardArray[row-1][column-1]=0;
                cout<<endl<<"   :( WRONG                    SCORE 【"<<score<<"】 ERROR 【"<<error<<"】"<<endl<<endl<<endl;;
                printBoard(boardArray);}}}
    cout<<"You finished with a score of "<<score<<" and "<<error<<" errors"<<endl;
    if(score==100){
        cout<<"= = = =  = = = = END OF THE GAME = == = = = = = = ="<<endl;
        cout<<"        Excellent , should try next level    "<<endl;}
    else if(score>=80 && score<100){
        cout<<"= = = =  = = = = END OF THE GAME = == = = = = = = ="<<endl;
        cout<<"        Good , keep practicing this level          "<<endl;}
    else if(score>=60&&score<80){
        cout<<"= = = =  = = = = END OF THE GAME = == = = = = = = ="<<endl;
        cout<<"OK Player...Keep Practicing This Level If You Dare "<<endl;}
    else if(score>=40&&score<60){
        cout<<"= = = =  = = = = END OF THE GAME = == = = = = = = ="<<endl;
        cout<<"        Well, suggest try a easier level           "<<endl;}
    else{
        cout<<"= = = =  = = = = END OF THE GAME = == = = = = = = ="<<endl;
        cout<<"  You may watch some online videos on how to play   "<<endl;}
    return 0;
}//}
bool SUDOKU::checkFinish(int boardQuestion[9][9],int baordAnswer[9][9]){        //检查是否完成
    int count=0;
    for(int a=0;a<9;a++){
        for(int b=0;b<9;b++){
            if(boardQuestion[a][b]!=baordAnswer[a][b]){count=count+1;}}}if(count==0)return true;else{ return false;}}
//游戏总进程
int SUDOKU::startGame(){
    SUDOKU game;
    char option;
    srand((unsigned)time(NULL));
    int randomChoose=rand()%10+1;
    while(true){
    cout<<"+---------------------------------------------------------------+"<<endl;
    cout<<"|= = = = = = = = = = WELCOME TO SUDOKU GAME = = = = = = = = =  =|"<<endl;
    cout<<"|                                                               |"<<endl;
    cout<<"|  >Please Select          S - start game                       |"<<endl;
    cout<<"|                          0 - quit game                        |"<<endl;
    cout<<"+---------------------------------------------------------------+"<<" > ";
    while(cin>>option){//cin>>option;
        if(option=='S'){break;}
        else if(option=='0'){cout<<endl;
            cout<<"                 【See You Next Time 】 "<<endl;
            cout<<endl<<endl;
            return 0;}
        else{
            cout<<"                   !  Invalid Entry  !        "<<endl;
            cout<<"           >Please Select    S - start game  "<<endl;
            cout<<"                             0 - quit game                        > "<<endl;}
    }
    cout<<endl;
    cout<<"      > Level 1 Very Esay      > Level 2 Esay    > Level 3 Medium         > Level 4 Hard       >";
    char level;
        while(cin>>level){
        if(level == '1'||level == '2'||level == '3'||level =='4'){   //executed once entry is valid and is one of four levels
            switch(level){
                case '1':
                    cout<<endl<<"               ----- MODE Very Esay -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1VeryEsay,sudoku1);return 0;
                        case 2:game.playGame(sudoku2VeryEsay,sudoku2);return 0;
                        case 3:game.playGame(sudoku3VeryEsay,sudoku3);return 0;
                        case 4:game.playGame(sudoku4VeryEsay,sudoku4);return 0;
                        case 5:game.playGame(sudoku5VeryEsay,sudoku5);return 0;
                        case 6:game.playGame(sudoku6VeryEasy,sudoku6);return 0;
                        case 7:game.playGame(sudoku7VeryEsay,sudoku7);return 0;
                        case 8:game.playGame(sudoku8VeryEsay,sudoku8);return 0;
                        case 9:game.playGame(sudoku9VeryEasy,sudoku9);return 0;
                        case 10:game.playGame(sudoku10VeryEsay,sudoku10);return 0;}
                case '2':
                    cout<<endl<<"               ----- MODE  Esay -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Esay,sudoku1);return 0;
                        case 2:game.playGame(sudoku2Esay,sudoku2);return 0;
                        case 3:game.playGame(sudoku3Esay,sudoku3);return 0;
                        case 4:game.playGame(sudoku4Esay,sudoku4);return 0;
                        case 5:game.playGame(sudoku5Esay,sudoku5);return 0;
                        case 6:game.playGame(sudoku6Easy,sudoku6);return 0;
                        case 7:game.playGame(sudoku7Esay,sudoku7);return 0;
                        case 8:game.playGame(sudoku8Esay,sudoku8);return 0;
                        case 9:game.playGame(sudoku9Easy,sudoku9);return 0;
                        case 10:game.playGame(sudoku10Esay,sudoku10);return 0;}
                case '3':
                    cout<<endl<<"               ----- MODE  Medium -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Midium,sudoku1);return 0;
                        case 2:game.playGame(sudoku2Medium,sudoku2);return 0;
                        case 3:game.playGame(sudoku3Medium,sudoku3);return 0;
                        case 4:game.playGame(sudoku4Medium,sudoku4);return 0;
                        case 5:game.playGame(sudoku5Medium,sudoku5);return 0;
                        case 6:game.playGame(sudoku6Medium,sudoku6);return 0;
                        case 7:game.playGame(sudoku7Medium,sudoku7);return 0;
                        case 8:game.playGame(sudoku8Medium,sudoku8);return 0;
                        case 9:game.playGame(sudoku9Medium,sudoku9);return 0;
                        case 10:game.playGame(sudoku10Medium,sudoku10);return 0;}
                case '4':
                    cout<<endl<<"               ----- MODE   Hard -----          "<<endl<<endl;
                    switch(randomChoose){
                        case 1:game.playGame(sudoku1Hard,sudoku1);return 0;
                        case 2:game.playGame(sudoku2Hard,sudoku2);return 0;
                        case 3:game.playGame(sudoku3Hard,sudoku3);return 0;
                        case 4:game.playGame(sudoku4Hard,sudoku4);return 0;
                        case 5:game.playGame(sudoku5Hard,sudoku5);return 0;
                        case 6:game.playGame(sudoku6Hard,sudoku6);return 0;
                        case 7:game.playGame(sudoku7Hard,sudoku7);return 0;
                        case 8:game.playGame(sudoku8Hard,sudoku8);return 0;
                        case 9:game.playGame(sudoku9Hard,sudoku9);return 0;
                        case 10:game.playGame(sudoku10Hard,sudoku10);return 0;}
            }}   //先结束switch 在结束if
        else if(level=='0'){cout<<endl;   //quit game as player want
            cout<<"                 【See You Next Time 】 "<<endl;
            cout<<endl<<endl;
            return 0;}
        else {
            cout<<endl;
            cout<<"                【 Invalid Entry  】"<<endl;
            cout<<endl;
            cout<<"      > Level 1 Very Esay      > Level 2 Esay    > Level 3 Medium         > Level 4 Hard       >";}
    }}
}


int main(){
    SUDOKU S1;
    S1.startGame();
}
