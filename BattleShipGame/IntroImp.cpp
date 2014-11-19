//Introduction Implementation
//By: Dayan
#include <iostream>
#include <string>
#include <conio.h>
#include "Intro.h"


#include <iomanip>

using namespace std;

void Intro::clearScreen()
{
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		/* Get the number of cells in the current buffer */
		if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		/* Fill the entire buffer with spaces */
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR) ' ',
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Fill the entire buffer with the current colors and attributes */
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
			)) return;

		/* Move the cursor home */
		SetConsoleCursorPosition( hStdOut, homeCoords );

}


void Intro::DisplayMSG(string TextToOutput, int width, bool endLine)
{

	if(endLine = true)
		cout << setw(width) << TextToOutput << "\n";
	else
		cout << setw(width) << TextToOutput;
}


int Intro::mShowWelcome()
{
char command;

do{
	DisplayMSG("********************************************************************************",2,true);
	DisplayMSG("*                                                                              *",2,true);
	DisplayMSG("*                                BATTLESHIP v0.1                               *",2,true);
	DisplayMSG("*                           By: Nathan, Dayan, Shaun                           *",2,true);
	DisplayMSG("*                                                                              *",2,true);
	DisplayMSG("********************************************************************************",2,true);
    DisplayMSG("                          |__												    ",1,true);
    DisplayMSG("                          |\/                                                   ",1,true);
    DisplayMSG("                          ---                                                   ",1,true);
    DisplayMSG("                         / | [                                                  ",1,true);
    DisplayMSG("                  !      | |||                                                  ",1,true);
    DisplayMSG("                _/|     _/|-++'                                                 ",1,true);
    DisplayMSG("            +  +--|    |--|--|_ |-                                              ",1,true);
    DisplayMSG("         { /|__|  |/\__|  |--- |||__/                                           ",1,true);
    DisplayMSG("        +---------------___[}-_===_.'____                        /\             ",1,true);
    DisplayMSG("   ____ `-' ||___-{]_| _[}-  |     |_[___\==--                   \/    _        ",1,true);
DisplayMSG("  __..._____--==/___]_|__|_____________________[___\==--____,-------------'.7       ",1,true);
DisplayMSG("_|                                                                   BB-61 /        ",1,true);
DisplayMSG("\\_________________________________________________________________________|        ",1,true);
DisplayMSG(" ~ ~ ~ ~ ~ ~ ~ ~ ~  ~ ~~  ~~ ~ ~ ~~ ~  ~~   ~  ~  ~ ~ ~  ~~ ~~ ~  ~  ~~ ~ ~ ~~~ ~ ~ ",1,true);
DisplayMSG("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~",1,true);


//MENU SYSTEM
//======================================
DisplayMSG("                          \"PRESS 's' TO START THE GAME\"                       ",1,true);
DisplayMSG("                                  to quit press 'q'                             ",1,true);

 command = getch();

	switch(command)
		{
		case 's':
		case 'S':
			clearScreen();
			return 0;
		break;

		case 'q':
		case 'Q':
			clearScreen();
			return 1;
		break;


		default:
			clearScreen();
			cout << "--> INCORRECT SELECTION <-- " << endl;
	    };
  command = ' ';
 }while(command != 's' || command != 'q' || command != 'Q' || command != 'S');


 return 0;
}



void Intro::mShowBackground()
{
cout<<"\n" << endl;
cout<<"Mr. McGuire ---->  %%%%                                            "<<endl;
cout<<"                  %%%%-(                                           "<<endl;
cout<<"                _%%%%%_/                                           "<<endl;
cout<<"              _%%%%%%%%                                            "<<endl;
cout<<"            _%%%%%%%/ \%                                           "<<endl;
cout<<"           %%%%%%%%%\\ \_                                          "<<endl;
cout<<"             %%%%%%   \ \\                                         "<<endl;
cout<<"                 )    /\_/                                         "<<endl;
cout<<"               /(___. \                                            "<<endl;
cout<<"               '----' (                                            "<<endl;
cout<<"               /       )                                            "<<endl;
cout<<"      ....___ _/       (_____ __ _ ___ ___ __ _ _ _____ _ _ ___     "<<endl;
cout<<"              /        )---...___ =-= = -_= -=_= _-=_-_ -=- =-_     "<<endl;
cout<<"            ,'         (         ```--.._= -_= -_= _-=- -_= _=-     "<<endl;
cout<<"         ,-'           )                 ``--._=-_ =-=_-= _-= _   "<<endl;
cout<<"        '-._    '-..___(                       ``-._=_-=_- =_-=     "<<endl;
cout<<"           ``---....__)                            `-._-=_-_=-     "<<endl;
cout<<"                )|)|                                  `-._=-_      "<<endl;
cout<<"                '-'-.\_                                    `-.     "<<endl;
cout<<"                                                                   "<<endl;
cout<<"\n" << endl;
}

//Constructor & Destructor
Intro::Intro()
{
  //NOTHING GOES ON

}

Intro::~Intro()
{
  //NOTHING GOES ON
}
