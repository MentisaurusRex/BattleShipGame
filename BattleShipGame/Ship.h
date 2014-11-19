#include <string>
#include <iostream>

using namespace std;

class Ship{
public:
	Ship(string, int);
	/*--------------------------------------------------
	Purpose: To declare what ship is being placed and how big it is.
	PreCondition: This function must have a name for the ship and how many 
		suqares long it is.
	PostCondition: The ship is declared with the given name and length.
	---------------------------------------------------*/
	string Name;
	int Height;
	int Width;
	int sqNum;
	char Alignment;
};