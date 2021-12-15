// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends here
// 

#include <iostream>
#include "HeaderTTT.h"
using namespace std;
enum arguments {programName, gameType, numberofArgs};

//takes in the input and prints out usage message 
int usageMessage(char* argv[]) 
{
    cout << "Usage: " << argv[programName] << " TicTacToe" << endl;
    return TicTacToeGame:: usageMessage; 
}

//takes in the input and starts the game and if it doesnt work, returns usagemessage 
int main(int argc, char*argv[] ) 
{
    if (argc == numberofArgs) 
    {
        if (argv[gameType] == string("TicTacToe"))
        {
            TicTacToeGame newGame; 
            return newGame.play();
        }
    }
    return usageMessage(argv); 
}
