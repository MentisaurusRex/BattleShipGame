//Introduction HeaderFile
//Headerfile used for displaying the welcome screen and background ASCII Image.
//By: Dayan

#include <string>
#include <Windows.h>

using namespace std;

class Intro
{
public:
	Intro();
	~Intro();

	/*--------------------------------------------------
	Purpose: To Display Welcome Screen.
	PreCondition: Must be executed prior to running game loop.
	PostCondition:Text and ASCII are written to screen.
	---------------------------------------------------*/
	int mShowWelcome();


	/*--------------------------------------------------
	Purpose: To clear console screen
	PreCondition: Must have something displayed on screen
	PostCondition: Screen will be clear and ready for output.
	---------------------------------------------------*/
	void clearScreen();

	/*--------------------------------------------------
	Purpose: To display a message on the screen
	PreCondition: Must pass in text, setw() integer and if you wish to use newLine (true/false)
	PostCondition: Will use cout to display msg to screen.
	---------------------------------------------------*/
	void DisplayMSG(string,int,bool);

    
	/*--------------------------------------------------
	Purpose: To draw background when game is running
	PreCondition: Use after clearing screen, then execute game so that background shows behind it.
	PostCondition: Background image in ASCII format will display behind battleship boards.
	---------------------------------------------------*/
	void mShowBackground();

private:
	//No Private Members
};
