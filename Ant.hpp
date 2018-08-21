/********************************************************************* 
** Program name: Proj1
** Author: Kristen Harrison
** Date: 8 July 2017
** Description: CS 162, Project 1. 
** The Ant class interface file declares the enum Direction, whose 
** instantiation stores the direction of the Ant, and the current row
** and column of the ant. There are two accessor functions for row and 
** column, and individual functions that pivot the ant or step it forward.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP



class Ant
{
private:
	enum Direction {NORTH, EAST, SOUTH, WEST};
	Direction direction;
	int antRow;
	int antCol;
public:
	Ant(int row = 0, int col = 0);
	int getRow();
	int getCol();
	void antPivot(char** grid);
	void nextStep(int numRows, int numCols);
};

#endif