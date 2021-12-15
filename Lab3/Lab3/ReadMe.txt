Arielle Rosenblatt
Lab 3 



This lab makes a viewable tic-tac-toe game that continuously shows the current states of the game and allows the user to 
input and get input for the next move of the game. Once the user moves, the game checks to see whether or not the move
is valid, and if it is, it updates the game states and either lets the game be completed successfully, stops it if the game 
reached a point where no moves are valid, or lets the user continue on to play if there are still valid moves to be played. 

I did not run into errors. 


Test Cases: 
1. I typed in Lab3.exe TicTacToeeee instead of Lab3.exe TicTacToe and it returned Usage: Lab3.exe TicTacToe which is correct. 
2. I typed in Lab3.exe TicTacToe and it returned: 
4
3
2
1
0
  0 1 2 3 4
Player X's turn!
Input coordinates here! Type quit to end game!

which is correct. 

3. I typed in an invalid input of "22" and it returned "Input not entered correctly! Enter coordinates
   with comma seperating them!" which is correct. 
4. I typed in an invalid move and it returned "Bad input! Try again! Input coordinates here! Type quit to end game!" 
5. I tested winning diagnolly and it returned: 
4
3       X
2   O X O
1   X X O
0
  0 1 2 3 4
Player X;2, 2;2, 1;1, 1;3, 3
Number of turns: 6
Player X won! 

which is correct (so it worked). 