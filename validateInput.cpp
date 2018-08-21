/********************************************************************* 
** Program name: Lab1
** Author: Kristen Harrison
** Date: 1 July 2017
** Description: CS 162, Lab 1. This is the implementation file for 
** reusable input validation functions. The string library is included 
** through the header file. Individual function descriptions below.
*********************************************************************/ 
#include "validateInput.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/*********************************************************************
** Description: The getInt function takes two parameters: the min and max
** of the acceptable range of int values. The function takes cin input
** as a string then validates it with validIntRange before returning 
** the user response as an integer.
*********************************************************************/ 
int getInt(int min, int max)
{
	string testString;
	int input;

	// store input as string and check validity
	std::getline(cin, testString);

	while (!validIntRange(testString, min, max))
	{
		cout << "Invalid input, please enter an integer between "
			 << min << " and " << max << endl;
		std::getline(cin, testString);
	}

	input = std::stoi(testString);	
	return input;
}



/*********************************************************************
** Description: The displayMenu function can be customized to print out
** listed options. It uses getInt to validate user input before returning
** that response as an int. 
*********************************************************************/ 
int menuChoice()
{
	cout << "Enter the number of your selection:\n"
		 << "1. Run program with default input\n"
		 << "2. Run program with custom input\n"
		 << "3. Run program with ant in random position\n"
		 << "4. Quit" << endl;

	int menuItem = getInt(1, 4);
	return menuItem;
}



/*********************************************************************
** Description: The isInteger function takes a single string parameter,
** and it returns true if the string represents an int (if the string 
** is not empty and every char, except the first if it is a minus sign, 
** is a digit), and returns false otherwise.  
*********************************************************************/ 
bool isInteger(string testString)
{
	bool validInt = true;

	if (testString.empty())
	{
		validInt = false;
	}

	// allows negative ints by checking first digit for minus sign
	if (!isdigit(testString[0]) && testString[0] != '-')
	{
		validInt = false;
	}

	// all other chars in string must be digits
	for (unsigned int i = 1; i < testString.length(); i++)
	{
		if (!isdigit(testString[i]))
		{
			validInt = false;
		}
	}

	return validInt;
}



/*********************************************************************
** Description: The validIntRange function takes as its parameters a 
** string and integer min and max values. It returns true if the string 
** represents an integer within the min/max range, and false otherwise.
*********************************************************************/ 
bool validIntRange(string testString, int min, int max)
{
	bool validRange = false;

	if (isInteger(testString))
	{
		int intInput = std::stoi(testString);

		if ((intInput >= min) && (intInput <= max))
		{
			validRange = true;
		}
	}

	return validRange;
}
