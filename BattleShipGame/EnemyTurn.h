#pragma once
#include "Map.h"
#include <string>

using namespace std;

class EnemyTurn : public Map
{
public:
	void eRndShot(Map);
	/*--------------------------------------------------
	Purpose: To generate a random shot for the computer
	PreCondition: Must have the map that will be fired onto declared (the players map).
		The maps must have already been defoned.
	PostCondition: A random point on the map is selected and checked, if it is a miss, 
		it is marked, if it is a hit, it is marked and the next shot will be a precise shot
		If it has already selected that spot, it tries another shot.
	---------------------------------------------------*/
	char ePreciseShot(Map, char);
		/*--------------------------------------------------
	Purpose: To have the computer focus on the area that your ship may be.
	PreCondition: You must declare what map you will fire into and what direction to fire 
		into, (W: up, D: right, S: down, A: left). Also the eRndShot must have hit a ship
		in order to call this function.
	PostCondition: The computer selects a spot attached to its last hit and begins to fire 
		around that spot. If it misses it moves to the next location, if it hits, it 
		continues to fire in the direction until it reaches water again.
	---------------------------------------------------*/

	int lhX, lhY;
	char nextShot;
	char shotType;
};
