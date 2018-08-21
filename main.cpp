/********************************************************************* 
** Program name: Proj1
** Author: Kristen Harrison
** Date: 8 July 2017
** Description: CS 162, Project 1: Langton's Ant 
** This project implements Langton's Ant, and allows the user to customize
** the size of the array, the number of steps, the location of the ant, 
** or the option of a default or a random ant starting location [Extra Credit].
** This program requires header and implementation files for the Ant and 
** Board classes and the validateInput library and the makefile. After
** unzipping, please run 'make' and './Proj1' or 'make memcheck' or 'make clean'.
********************************************************************/ 
#include <iostream>
#include "Board.hpp"
#include "validateInput.hpp"
using std::cout;
using std::endl;

void runGame(int choice);


/*********************************************************************
** Description:  Since option 4 in the menu is Quit, the do-while loop
** block will repeat as long as the user wants to run the program again.
** In order to avoid using multiple return statements, no additional code 
** should be added in main after the do-while loop. 
*********************************************************************/ 
int main()
{
	int progVersion;

	do
	{
		progVersion = menuChoice();

		if (progVersion != 4)
		{
			runGame(progVersion);
		}
	} while (progVersion != 4);

	return 0;
}



/*********************************************************************
** Description: The runGame function is called every time the user wants
** to play or replay the game. Its single parameter is the menu item
** chosen by the user. This function sets defaults, and then runs 
** conditional statements to create the program version requested by the user.
*********************************************************************/ 
void runGame(int choice)
{
	const int ROW_MAX = 70, 
			  COL_MAX = 70,
			  STEPS_MAX = 100;

	int numRows = 20,
		numCols = 40,
		numSteps = 10,
		startRow = 10,
		startCol = 20;


	//the numbers for option 1 (default) are already set
	if (choice > 1) 
	{
		cout << "Enter number of rows up to " << ROW_MAX << endl;
		numRows = getInt(1, 70);

		cout << "Enter number of columns up to " << COL_MAX << endl;
		numCols = getInt(1, 70);

		cout << "Enter the number of ant steps up to " << STEPS_MAX << endl;
		numSteps = getInt(0, 100);

		if (choice == 2) // custom input
		{
			cout << "Enter starting row of ant (0 to " << numRows-1 << ")" << endl;
			startRow = getInt(0, numRows - 1);

			cout << "Enter starting column of ant (0 to " << numCols-1 << ")" << endl;
			startCol = getInt(0, numCols - 1);
		}
		else if (choice == 3) // ant in random starting location
		{
			startRow = rand() % numRows;
			startCol = rand() % numCols;
		}
	}

	Board board = Board(numRows, numCols, startRow, startCol);
	board.moveAnt(numSteps);
}







