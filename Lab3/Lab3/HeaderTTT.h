//Header file
//Is where the main classes for the game is and also the enumerations 
#pragma once 
using namespace std;
#include <iostream>
#include <vector>
#include <sstream>

class TicTacToeGame {
    friend ostream& operator<<(ostream &x, const TicTacToeGame &piece); //makes ostream a friend so it can access the private members
private:
    int width;
    int height;
    vector <string> type; 
    bool player1Turn = true;
    string XMoves;
    string OMoves;

public: 
    TicTacToeGame(); 
    bool done();
    bool draw(); 
    int prompt(unsigned int &a, unsigned int &b); 
    int turn(); 
    int play(); 
    

    enum returnValues{endGame, continueGame, invalidInput, usageMessage};
};

ostream& operator<<(ostream &x, const TicTacToeGame &piece);

