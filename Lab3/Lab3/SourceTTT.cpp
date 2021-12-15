//SourceTTT is the place where all the logic and execution for the game is 
#include "HeaderTTT.h"


//starting state of the game
TicTacToeGame:: TicTacToeGame():width(5), height(5), XMoves("Player X"), OMoves("Player O") 
{
	for (int i = 0; i < width * height; i++)
	{
		type.push_back(" ");
	}
}

//sets up the ostream and set up the board
ostream& operator<<(ostream &O, const TicTacToeGame &piece) 
{
	
	for (int y = piece.height - 1; y >= 0; y--) //starting from top and going down
	{
		O << y;
		O << " ";

		for (int x = 0; x < piece.width; x++)
		{
			int vectorIndex = piece.width *(y)+x;
			const string& pieceString = piece.type[vectorIndex]; 

			O << pieceString << " ";
		}
		O << endl;
	}

	O << " " << " ";

	for (int i = 0; i < piece.width; i++)
	{
		O << i << " ";
	}
	return O; 
}

//method returns true if 3-Xs or Os are in a vertical, horizontal or diagonal line; otherwise returns false
bool TicTacToeGame:: done() 

{
	for (int h = 0; h < height; h++)  //goes through the columns
	{
		int counter = 0; //creates counter to keep track
		for (int w = 0; w < width -1; w++) //goes through the rows
		{
			int i = h * width + w;
			if (type[i] == type[i + 1] && type[i] != " ")
			{
				counter++;
			}
		}
		//-2 because you dont count the borders, and then -1 
		//because counting number of pairs of which there are width-1
		if (counter == width - 3) 
		{
			return true; 
		}
	}

	for (int w = 0; w < width; w++) //goes through rows
	{
		int counter = 0; //makes a counter to keep track
		for (int h = 0; h < height - 1; h++) //goes through height
		{
			int i = h * width + w;
			if (type[i] == type[i + width] && type[i] != " ")
			{
				counter++;
			}
		}
		//-2 because you dont count the borders, and then -1 
		//because counting number of pairs of which there are width-1
		if (counter == height - 3)
		{
			return true;
		}
	}

	int counter = 0;
	for (int h = 0; h < height - 1; h++) //diagnol
	{
		int i = h * width + h;
		if (type[i] == type[i + 1 + width] && type[i] != " ")
		{
			counter++;
		}
	}
	//-2 because you dont count the borders, and then -1 
	//because counting number of pairs of which there are width-1
	if (counter == height - 3)
	{
		return true;
	}

	counter = 0;
	for (int h = 0; h < height - 1; h++) //diagnol
	{
		int i = h * width + (width - 1 - h);
		if (type[i] == type[i + 1 - width] && type[i] != " ")
		{
			counter++;
		}
	}
	//-2 because you dont count the borders, and then -1 
	//because counting number of pairs of which there are width-1
	if (counter == height - 3)
	{
		return true;
	}

	return false;
}

//returns false if there are moves remaining in the game or if the done() method returns true; 
//otherwise (if there are no more moves remaining and the game has not been completed successfully) returns true
bool TicTacToeGame:: draw() 
{
	for (int h = 1; h < height - 1; h++) //not including borders, goes through the columns
	{
		for (int w = 1; w < width - 1; w++) //not including borders, goes through the rows
		{
			int index = h * width + w;
			if (type[index] == " ")
			{
				return false; 
			}
		}
	}
	
	return !done();
}


//uses cout to prompt the user to type either "quit" to end the 
//game or to type a valid coordinate on the board seperated by the comma 
int TicTacToeGame:: prompt(unsigned int &a, unsigned int &b) 
{
	string input;
	cout << " Input coordinates here! Type quit to end game! " << endl; //prints this out to user
	cin >> input; 

	if (input == "quit")
	{
		cout << "User ended game! " << endl; 
		return endGame; //ends the game
	}
	else {
		size_t search = input.find(','); //looks for comma 
		if (search == string::npos) //if it doesnt have the correct input 
		{
			cout << " Input not entered correctly! Enter coordinates with comma seperating them!" << endl;
			return prompt(a, b); //call recursively so it continues 
		}
		
		input[search] = ' '; //change comma to space
		
		istringstream coord1(input); 
		if (coord1 >> a >> b)
		{
			if (a < (unsigned int) width -1 && a != 0) // if valid input
			{
				if (b < (unsigned int) height - 1 && b != 0) // if valid input
				{
					return continueGame;
				}
			}

		}
			cout << "Bad input! Try again!"; 
			return prompt(a, b); //recursive, so asks again
	}
}

//remembers whos turn it is/alternates whos turn it is and prints out whos turn it is, 
//along with seeing if valid coordinates were entered or if the user had quit 
int TicTacToeGame::turn() 
{
	string type;
	unsigned int x, y;
	if (player1Turn)
	{
		cout << "Player X's turn!" << endl;
		type = "X";
	}
	else
	{
		cout << "Player O's turn!" << endl;
		type = "O";
	}

	while (true) {
		if (prompt(x, y) == endGame)
		{
			return endGame;
		}
		else
		{
			int index = y * width + x;
			if (this->type[index] != " ") //pointer and dot -- differentiator from type variable from above
			{
				cout << "Enter a valid coordinate!" << endl;
				continue;
			}

		}
		break;

	}
	int index = y * width + x;

	this->type[index] = type;
	cout << *this << endl; //prints out print method from beg. 

	ostringstream PlayersMove;
	PlayersMove << x << ", " << y;
	if (player1Turn)
	{
		XMoves += ";" + PlayersMove.str();
		cout << XMoves << endl;
		player1Turn = false;
	}
	else
	{
		OMoves += "; " + PlayersMove.str();
		cout << OMoves << endl; 
		player1Turn = true; 
	}
	
	return continueGame;
}

//continuously calls the turn() and done() and draw () methods until the done method returns true (then prints out who won)
//or the draw method returns true (prints out how many turns and the game is a draw)  
//or the user quits (prints out message of how many turns played and that the user quit) 
int TicTacToeGame:: play()
{
	cout << *this << endl;
	int end; 
	bool Winner; 
	bool whosTurn; 
	int counter = 0; 
	
	//while ((end = turn()) != endGame && (Winner = !done()) && (whosTurn = !draw()));
	while ((end = turn()) != endGame && (Winner = !done()) && (whosTurn = !draw()))
	{
		counter++; 
		cout << "Number of turns: " << counter << endl;


	}




	if (end == endGame)
	{
		return endGame;
	}
	
	else if (!Winner) //winner is true (there is a winner) 
	{
		cout << "Number of turns: " << counter << endl;
		if (player1Turn)
		{
			cout << "Player O won!" << endl;
		}
		else
		{
			cout << "Player X won!" << endl;
		}
	}

	else if (!whosTurn)
	{
		cout << "It was a draw!" << endl; 
		return endGame; 
	}

	return endGame; 
}
