/********************************************************************* 
** Program name: Lab1
** Author: Kristen Harrison
** Date: 1 July 2017
** Description: CS 162, Lab 1. This is the header file for input validation
** functions. The primary functions useful to outside programs are getInt(),  
** which handles user input and return a validated integer, and displayMenu(), 
** which handles a menu list and returns the user's integer choice. The
** other functions, isInteger() and validIntRange(), are helper functions 
** that can be used to check whether a string represents an integer, and 
** whether that integer is within a specified range. 
*********************************************************************/
#ifndef VALIDATE_INPUT_HPP
#define VALIDATE_INPUT_HPP

#include <string>

int getInt(int min, int max);
bool isInteger(std::string testString);
bool validIntRange(std::string testString, int min, int max);
int menuChoice();

#endif