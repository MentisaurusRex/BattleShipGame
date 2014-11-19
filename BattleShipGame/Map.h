#include <string>
#include "Ship.h"
using namespace std;
class Map {

public: 
	void Loading();
	/*--------------------------------------------------
	Purpose: To draw a loading bar to the screen.
	PreCondition: The random ship placement must be called.
	PostCondition: A loading bar is drawn to the screen.
	---------------------------------------------------*/
	void unLoading();
	/*--------------------------------------------------
	Purpose: To undraw a loading bar to the screen.
	PreCondition: The random ship placement must be completed.
	PostCondition: A loading bar is undrawn to the screen.
	---------------------------------------------------*/
	void SetMap();
	/*--------------------------------------------------
	Purpose: To set the default maps full of water with no boats placed.
	PreCondition: You must have a map object you wish to set declared.
	PostCondition: The two map structures will be set to be all water with 
	no placed ships. 
	---------------------------------------------------*/
	void eDrawMap();
	/*--------------------------------------------------
	Purpose: To draw the enemy map to the screen.
	PreCondition: You must have the enemy map object created and you must 
		use the SetMap() function on it.
	PostCondition: The enemy map is drawn to the screen and only shows 
		water and places hit.
	---------------------------------------------------*/
	void pDrawMap();
	/*--------------------------------------------------
	Purpose: To draw the player map to the screen.
	PreCondition: You must have the player map object created and you must 
		use the SetMap() function on it.
	PostCondition: The player map is drawn to the screen and shows
		your ships and where the computer has attacked you.
	---------------------------------------------------*/
	void placeShips(Ship, Map&);
	/*--------------------------------------------------
	Purpose: To allow the player to select where they put their ships.
	PreCondition: This function must include what ship is to be placed
		and on what map it will be placed on.
	PostCondition: The moves where they want to place their ship and hits 
	the enter key to place it on the map.
	---------------------------------------------------*/
	void rndShips(Ship CShip);
	/*--------------------------------------------------
	Purpose: To randomly select where the enemies ships are placed.
	PreCondition: This function must include what ship is to be placed
		and on what map it will be placed on.
	PostCondition: The enemy map array structure stores where the ship is 
		placed.
	---------------------------------------------------*/
	bool IsPassable(int MapX, int MapY);
	/*--------------------------------------------------
	Purpose: To determnine when placing your ships if you are moving out 
		of the map area.
	PreCondition: This function must recieve how large the map is in the form of 
		its maximum X and Y coordinates.
	PostCondition: The function returns whether the ship is trying to be placed
		off of the map.
	---------------------------------------------------*/

	bool IsPlaceable(Ship PShip, int MapX, int MapY);
	/*--------------------------------------------------
	Purpose: To determnine when placing your ships if you are trying to place it
		on top of another ship.
	PreCondition: This function must recieve how large the map is in the form of 
		its maximum X and Y coordinates, it also must know what ship is trying to 
		be placed.
	PostCondition: The function returns whether the ship is trying to be placed
		on top of another ship.
	---------------------------------------------------*/
		
	//Player firing sequence
	void OpenFire();
	/*--------------------------------------------------
	Purpose: To allow the player to select where on the enemy map he wishes to fire.
	PreCondition: The map objects must be initialized and drawn to the screen.
	PostCondition: The player moves the cursor where he wants to fire and then hits
		enter to see if a ship is there.
	---------------------------------------------------*/

	//Enemies firing sequence
	void eRndShot();
	/*--------------------------------------------------
	Purpose: To generate a random shot for the computer
	PreCondition: The maps must have already been defined.
	PostCondition: A random point on the map is selected and checked, if it is a miss, 
		it is marked, if it is a hit, it is marked and the next shot will be a precise shot
		If it has already selected that spot, it tries another shot.
	---------------------------------------------------*/
	char ePreciseShot(char);
	/*--------------------------------------------------
	Purpose: To have the computer focus on the area that your ship may be.
	PreCondition: You must declare what direction to fire 
		into, (W: up, D: right, S: down, A: left). Also the eRndShot must have hit a ship
		in order to call this function.
	PostCondition: The computer selects a spot attached to its last hit and begins to fire 
		around that spot. If it misses it moves to the next location, if it hits, it 
		continues to fire in the direction until it reaches water again.
	---------------------------------------------------*/
	int lhX, lhY;
	char nextShot;
	char shotType;
	bool pSuc;
	bool hSuc;
	//--------------


	struct Tiles{
		bool hit;
		bool placed;
		string tileName;
		int tileType;
	};
	static const int HEIGHT = 10;
	static const int WIDTH = 15;
	Tiles MapArray[HEIGHT][WIDTH];
	int ShipNumber;
	int NumOfHits;
private:
};
