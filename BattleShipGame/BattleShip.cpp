// BattleShip.cpp : Defines the entry point for the console application.
//
#include "Map.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include "Intro.h""

using namespace std;

int main()            
{
	bool MainLoop = true;
	while (MainLoop){
	bool GameLoop = true;
	Intro newIntro;
	if(newIntro.mShowWelcome() == 1)
		return 0;
    
	//Display Background
	newIntro.clearScreen();
	newIntro.mShowBackground();


	int x,y;
	string xCoord;
	string yCoord;
	//creates map objects.
	Map youMap;
	Map enemyMap;
	
	//sets map objects.
	youMap.SetMap();
	enemyMap.SetMap();

	//draws maps to screen for first time
	youMap.pDrawMap();
	enemyMap.eDrawMap();

	//creates all ship objects.
	Ship Cruiser("Cruiser",3);
	Ship AircraftCarrier("AircraftCarrier", 5);
	Ship Submarine("Submarine", 3);
	Ship BattleShip("BattleShip", 4);
	Ship Destroyer("Destroyer", 2);

	//Program lets player place their ships
	youMap.placeShips(Cruiser, youMap);
	youMap.placeShips(AircraftCarrier, youMap);
	youMap.placeShips(Submarine, youMap);
	youMap.placeShips(BattleShip, youMap);
	youMap.placeShips(Destroyer, youMap);
	
	youMap.Loading(); //draws loading bar, this next part takes a while.

	//Program stores enemy ships.
	enemyMap.rndShips(Cruiser);
	enemyMap.rndShips(AircraftCarrier);
	enemyMap.rndShips(Submarine);
	enemyMap.rndShips(BattleShip);
	enemyMap.rndShips(Destroyer);

	youMap.unLoading();

	//Sets random shot type.
	youMap.shotType = 'r';
	youMap.nextShot = 'w';

	//sets how default ship hits and how many squares must be hit for victory.
	youMap.ShipNumber = 17;
	youMap.NumOfHits = 0;
	enemyMap.ShipNumber = 17;
	enemyMap.NumOfHits = 0;
	youMap.pSuc = false;
	enemyMap.hSuc = false;

	while (GameLoop){ //Main game loop

		youMap.pDrawMap();
		enemyMap.eDrawMap();

		//while player hasn't had a succesful attack it prompts him to pick a spot.
		while (enemyMap.hSuc == false){		
		enemyMap.OpenFire();
		enemyMap.eDrawMap();
		}
		enemyMap.hSuc = false;

		//Checks if player won and will end the game loop.
		if(enemyMap.NumOfHits == enemyMap.ShipNumber){
			cout << "You Win!" << endl;
			cout << "Press any key to go back to Main." << endl;
			GameLoop = false;
			youMap.shotType = 'n';
		}
		
		//Checks to see if computer fires randomly.
		if(youMap.shotType == 'r'){
			youMap.eRndShot();
		}
		//Checks to see if computer fires precisley.
		else if (youMap.shotType == 'p'){
			while (youMap.pSuc == false){
			youMap.nextShot = youMap.ePreciseShot(youMap.nextShot);
			}
			youMap.pSuc = false;
		}
		//checks if computer wins, it it does, ends game loop.
		if(youMap.NumOfHits == youMap.ShipNumber){
			cout << "You Lose" << endl;
			cout << "Press any key to go back to Main." << endl;
			GameLoop = false;
		}
		
	}//end of while
	}
	return 0;
}

