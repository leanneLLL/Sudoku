//
//  Wordladder.hpp
//  Word-Ladder
//
//  Created by Bing Lin on 10/4/20.
//
#ifndef Wordladder_hpp
#define Wordladder_hpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Graph.hpp"
using namespace std;

class Wordladder {
private:
    string initialWord;//start word
    string finalWord;//end word
    ifstream wordsFile; //file ready to open
    vector<string> dictionary; // put word from dictionary inside
    vector<string>::iterator dictionaryIt; // iterator
    void loadWords() {
        string tempWord;//find common letters
        bool first=false, second=false, third=false, fourth=false;
        short int numLettersInCommon = 0;//similiarity of two words
        short int x=-1, y=-1, z=-1;
        for (int i = 0; i < 4; i++) {
            if (initialWord[i] == finalWord[i]) {
                if (i == 0) { first=true; numLettersInCommon++; }
                else if (i == 1) { second=true; numLettersInCommon++; }
                else if (i == 2) { third=true; numLettersInCommon++; }
                else { fourth=true; numLettersInCommon++; }
            }//check the each letters between two words
        }
        wordsFile.clear();
        wordsFile.seekg(0, ios::beg);
        switch (numLettersInCommon) {
            case 1://when have one same letter
                if (first) x=0;
                else if (second) x=1;
                else if (third) x=2;
                else if (fourth) x=3;
                while (!wordsFile.eof()) {
                    wordsFile >> tempWord;
                    if (tempWord[x] == initialWord[x]) {
                        dictionary.push_back(tempWord); // load word into list
                    }
                }
                break;
            case 2:
                if (first) {
                    x=0;
                    if (second) y=1;
                    else if (third) y=2;
                    else if (fourth) y=3;
                }
                else if (second) {
                    x=1;
                    if (third) y=2;
                    else if (fourth) y=3;
                }
                else if(third) {
                    x=2;
                    y=3;
                }
                
                while (!wordsFile.eof()) {
                    wordsFile >> tempWord;
                    // test the conditions
                    if (tempWord[x] == finalWord[x] && tempWord[y] == finalWord[y]) {
                        dictionary.push_back(tempWord); // load word
                    }
                }
                break;
            case 3:
                if (first) {
                    x=0;
                    if (second) {
                        y=1;
                        if (third) z=2;
                        else if (fourth) z=4;
                    }
                    else if (third) {
                        y=2;
                        z=3;
                    }
                }
                else if (second) {
                    x=1;
                    if (third) {
                        y=2;
                        z=3;
                    }
                }
                
                while (!wordsFile.eof()) {
                    wordsFile >> tempWord;
                    // test the conditions
                    if (tempWord[x] == initialWord[x] && tempWord[y] == initialWord[y] && tempWord[z] == initialWord[z]) {
                        dictionary.push_back(tempWord); // load word into list
                    }
                }
                break;
            case 4://exactly same word
                cerr << "WARNING : \nEntered two same words, please re-start\n";
                exit(1);
                break;
            default://two completely different word, execute these
                while (!wordsFile.eof()) {
                    wordsFile >> tempWord;
                    dictionary.push_back(tempWord); // load word into list
                }
                break;
        }
    }
    void getWords(){
        cout << "\nGame Rule : Enter 2 different words (each must have four letters)\n" << endl;
        cout<<"You may enter below---\n";
        cout << "Initial Word: ";
        cin >> initialWord;
        while (initialWord.length() != 4) {//if word entered does not meet criteria
            cerr << "Invalid entry, please re-enter";
            cout << "Initial Word: ";
            cin >> initialWord;
        }
        cout << "Final Word: ";
        cin >> finalWord;
        while (finalWord.length() != 4) { //check if meet criteria
            cerr << "Invalid entry, please re-enter";
            cout << "Final Word: ";
            cin >> finalWord;
        }
        for (int i = 0; i < initialWord.length(); i++) {
            initialWord[i] = initialWord[i] & 0xDF;
            finalWord[i] = finalWord[i] & 0xDF;
        }
    }
    int checkWords(){
        string tempWord;
        bool word1Found = false;
        bool word2Found = false;
        while (!wordsFile.eof() && (word1Found != true || word2Found != true)) {
            wordsFile >> tempWord;
            if (initialWord == tempWord) word1Found = true;
            if (initialWord == tempWord) word2Found = true;
        }
        if (word1Found == true && word2Found == true) {
            return 0;
        }
        else {
            cerr << "Word cannot be found\n";
            exit(1);
        }
    }
    void gameSolution(){
        Graph g(dictionary);
        // Get shortest path
        list<string> lePath = g.shortestPath(initialWord, finalWord);
        cout << "Solved ladder: " << endl;
        for (list<string>::iterator it = lePath.begin(); it != lePath.end(); ++it) {
            cout << *it << endl;
        }
    }
public:
    Wordladder(){
        wordsFile.open("/Users/binglin/Desktop/words.txt");
        if (wordsFile.fail()) {
            cout << "ERROR: Unable to open file" << endl;
            exit(1);
        }
    }
    ~Wordladder(){
        wordsFile.close();
    }
    void gameStart(){
        getWords();
        checkWords();
        loadWords();
        gameSolution();
    }
};

#endif /* Wordladder_hpp */


