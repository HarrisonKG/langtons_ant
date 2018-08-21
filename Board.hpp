/********************************************************************* 
** Program name: Proj1
** Author: Kristen Harrison
** Date: 8 July 2017
** Description: CS 162, Project 1. 
** The Board class interface file declares the data members for Board
** and includes the Ant class interface file. Board is the parent class
** of Ant, and Board manages and updates the grid array by calling 
** functions through its ant object. This makes the program more scalable
** by making it easier to update the code to allow for multiple ants.
** The constructor includes default values in case a default constructor 
** is ever needed.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"


class Board 
{
private:
	int numRows;
	int numCols;
	int startRow;
	int startCol;
	char** grid;
	Ant ant;
public:
	Board(int rows = 20, int cols = 40, int rowA = 10, int colA = 20);
	void moveAnt(int numSteps);
	void print();
	~Board();
};

#endif