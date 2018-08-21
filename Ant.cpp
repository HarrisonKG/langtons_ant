/********************************************************************* 
** Program name: Proj1
** Author: Kristen Harrison
** Date: 8 July 2017
** Description: CS 162, Project 1. 
** The Ant class implementation file defines the constructor and functions
** for the Ant class. Note the constructor is set to default values in
** the header file in case a default constructor is needed. Individual
** function descriptions are below.
*********************************************************************/
#include <iostream> 
#include "Ant.hpp"
using std::cout;
using std::endl;



/*********************************************************************
** Description: The Ant constructor takes two parameters: the row and
** column of the ant's location. The constructor also sets the ant's
** direction to NORTH. 
*********************************************************************/
Ant::Ant(int row, int col)
{
	antRow = row; 
	antCol = col;

	direction = NORTH;
}



/*********************************************************************
** Description: The getRow function returns the ant's current row
*********************************************************************/
int Ant::getRow()
{
	return antRow;
}



/*********************************************************************
** Description: The getCol function returns the ant's current column
*********************************************************************/
int Ant::getCol()
{
	return antCol;
}



/*********************************************************************
** Description: The antPivot function takes the grid pointer as a parameter
** and updates the gridsquare's color and the ant's cardinal direction.
** Because NORTH is 0, EAST is 1, SOUTH is 2, and WEST is 3, the algorithm 
** counts up by one (unless already 3) to turn right, and down by one
** (unless already 0) to turn left. 
*********************************************************************/
void Ant::antPivot(char** grid)
{
	// on white tile, turn right and paint it black
	if (grid[antRow][antCol] == ' ')
	{
		if (direction < 3)
		{
			direction = static_cast<Direction>(direction + 1);
		}
		else 
		{
			direction = NORTH;
		}
		grid[antRow][antCol] = '#';
	}
	// on black tile, turn left and paint it white
	else if (grid[antRow][antCol] == '#')
	{
		if (direction > 0)
		{
			direction= static_cast<Direction>(direction - 1);
		} 
		else
		{
			direction = WEST;
		}
		grid[antRow][antCol] = ' ';
	}
}



/*********************************************************************
** Description: The nextStep function takes two parameters: the numbers 
** of rows and columns in the grid. Depending on the ant's orientation, 
** the row or column of the ant's location is incremented or decremented.
** If the ant moves off the edge of the grid, it reappears on the other side.
*********************************************************************/
void Ant::nextStep(int numRows, int numCols)
{
	if (direction == NORTH)
	{
		if (antRow > 0)
		{
			antRow--;
		} 
		else
		{
			antRow = numRows - 1;
		}
	}
	else if (direction == EAST)
	{
		if (antCol < numCols - 1)
		{
			antCol++;
		}
		else
		{
			antCol = 0;
		}
	}
	else if (direction == SOUTH)
	{
		if (antRow < numRows - 1)
		{
			antRow++;
		}
		else
			antRow = 0;
	}
	else if (direction == WEST)
	{
		if (antCol > 0)
		{
			antCol--;
		}
		else 
		{
			antCol = numCols - 1;
		}
	}
}
