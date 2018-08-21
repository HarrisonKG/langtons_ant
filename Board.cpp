/********************************************************************* 
** Program name: Proj1
** Author: Kristen Harrison
** Date: 8 July 2017
** Description: CS 162, Project 1. 
** The Board class implementation file defines the constructor and functions
** of the Board class. Creation of a Board object creates a dynamically
** allocated array and an Ant object. The moveAnt function moves the ant
** for the specified number of steps, and the destructor deletes the array.
*********************************************************************/
#include "Board.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;



/*********************************************************************
** Description: The Board constructor takes four parameters: the number
** of rows and columns for the array, and the row-coordinate and column-
** coordinate of the ant. The constructor initializes these and then 
** creates the dynamically allocated grid array and an ant object. 
*********************************************************************/
Board::Board(int rows, int cols, int rowA, int colA)
{
	numRows = rows;
	numCols = cols;
	startRow = rowA;
	startCol = colA;

	// create grid as an array of pointers to char arrays
	grid = new char*[numRows];

	for (int i = 0; i < numRows; i++)
	{
		grid[i] = new char[numCols];
	}

	// grid starts all white
	for (int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			grid[i][j] = ' ';
		}
	}

	ant = Ant(startRow, startCol);
}



/*********************************************************************
** Description: The moveAnt function controls the overall flow by counting 
** the number of steps required, and at each step printing the board, 
** turning the ant, and advancing it one gridsquare forward. 
*********************************************************************/
void Board::moveAnt(int numSteps)
{
	for (int i = 0; i < numSteps; i++)
	{
		print();
		ant.antPivot(grid);
		ant.nextStep(numRows, numCols);
	}
}



/*********************************************************************
** Description: The print function loops through the grid array and prints
** the values there to the console. It also prints a star border around 
** the array to aid visualization, and substitutes the '@' symbol at the 
** ant's current location. 
*********************************************************************/
void Board::print()
{
	// assigns string for top and bottom border
	string border;
	border.assign(numCols + 2, '*');
	cout << border << endl;

	for (int i = 0; i < numRows; i++)
	{
		cout << '*';

		for(int j = 0; j < numCols; j++)
		{
			// show ant's position on grid
			if (i == ant.getRow() && j == ant.getCol())
			{
				cout << '@';
			}
			else 
			{
				cout << grid[i][j];
			}
		}
		cout << '*' << endl;
	}
	cout << border << endl << endl;
}



/*********************************************************************
** Description: The destructor checks that the grid pointer is not yet null,
** then frees the dynamically allocated memory and sets pointers to null. 
*********************************************************************/
Board::~Board()
{
	if (grid)
	{
		for(int i = 0; i < numRows; i++) 
		{
	    	delete [] grid[i];
	    	grid[i] = 0;
		}

		delete [] grid;
		grid = 0;
	}

}
