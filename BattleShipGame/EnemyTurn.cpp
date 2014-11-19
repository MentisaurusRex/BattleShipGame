#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Map.h"

using namespace std;

void Map::eRndShot()
{
	int x;
	int y;
	bool goodTry = true;
	
while (goodTry){

	srand ( time(NULL) );
	x = rand() % 15;
	y = rand() % 10;

if(MapArray[y][x].hit == true)
{
  goodTry = true;
}
else if(MapArray[y][x].placed == true && MapArray[y][x].hit == false)
{
  MapArray[y][x].tileType = 4;
  lhY = y; 
  lhX = x;
  MapArray[y][x].hit = true;
  shotType = 'p';
  NumOfHits += 1;
  goodTry = false;
}
else if(MapArray[y][x].placed == false)
{
  MapArray[y][x].tileType = 3;
  MapArray[y][x].hit = true;
  goodTry = false;
}
//
}//end good try if
pDrawMap();
}

char Map::ePreciseShot(char shot){
	
	int x, y;
	if (shot =='w'){
		x = lhX;
		y = lhY - 1;
		if(MapArray[y][x].hit == true){
			return 'd';
		}
		else if(MapArray[y][x].placed == true && MapArray[y][x].hit != true){
			MapArray[y][x].hit = true;
			MapArray[y][x].tileType = 4;
			lhY = y;
			pSuc = true;
			NumOfHits += 1;
			return 'w';
		}
		else if(MapArray[y][x].placed != true){
			MapArray[y][x].hit = true;
			MapArray[y][x].tileType = 3;
			pSuc = true;
			return 'd';
		}
		
	}
	if (shot =='d'){
		x = lhX + 1;
		y = lhY;
		if(MapArray[y][x].hit == true){
			return 's';
		}
		else if(MapArray[y][x].placed == true && MapArray[y][x].hit != true){
			MapArray[y][x].hit = true;
			MapArray[y][x].tileType = 4;
			lhX = x;
			pSuc = true;
			NumOfHits += 1;
			return 'd';
		}
		else if(MapArray[y][x].placed != true){
			MapArray[y][x].tileType = 3;
			MapArray[y][x].hit = true;
			pSuc = true;
			return 's';
		}
		
	}
	if (shot =='s'){
		x = lhX;
		y = lhY + 1;
		if(MapArray[y][x].hit == true){
			return 'a';
		}
		else if(MapArray[y][x].placed == true && MapArray[y][x].hit != true){
			MapArray[y][x].tileType = 4;
			MapArray[y][x].hit = true;
			lhY = y;
			pSuc = true;
			NumOfHits += 1;
			return 's';
		}
		else if(MapArray[y][x].placed != true){
			MapArray[y][x].tileType = 3;
			MapArray[y][x].hit = true;
			pSuc = true;
			return 'a';
		}
		
	}
	if (shot =='a'){
		x = lhX - 1;
		y = lhY;
		if(MapArray[y][x].hit == true){
			shotType = 'r';
			return 'w';
		}
		else if(MapArray[y][x].placed == true && MapArray[y][x].hit != true){
			MapArray[y][x].hit = true;
			MapArray[y][x].tileType = 4;
			lhX = x;
			pSuc = true;
			NumOfHits += 1;
			return 'a';
		}
		else if(MapArray[y][x].placed != true){
			MapArray[y][x].hit = true;
			MapArray[y][x].tileType = 3;
			shotType = 'r';
			pSuc = true;
			return 'w';
		}
		
	}
	pDrawMap();
}

void Map::OpenFire(){
	int x = 0, y = 0;
	char bKey;
	bool placeLoop = true;
	         MapArray[y][x].tileType = 1;

	x = 0;
	y = 0;
	while(placeLoop){
		eDrawMap();
		bKey = getch();
		switch(bKey){

			case 'w':

					if (IsPassable(x, y - 1)){
						MapArray[y][x].tileType = 0;

						MapArray[y - 1][x].tileType = 1;
					y = y - 1;
					}
				break;
			case 'd':

					if (IsPassable(x + 1, y)){
						MapArray[y][x].tileType = 0;
					
						MapArray[y][x + 1].tileType = 1;
					x = x + 1;
					}
				break;
			case 'a': 

					if (IsPassable(x - 1, y)){
						MapArray[y][x].tileType = 0;
					
						MapArray[y][x - 1].tileType = 1;
					x = x - 1;
					}
				break;
			case 's': 

					if (IsPassable(x, y + 1)){
							MapArray[y][x].tileType = 0;

							MapArray[y + 1][x].tileType = 1;
					y = y + 1;
					}
				break;
			case 13:	
				bool HasHit = true;
						if (MapArray[y][x].hit == true){
						hSuc = false;
							if (MapArray[y][x].placed == true){
								MapArray[y][x].tileType = 4;
							}
							else {
								MapArray[y][x].tileType = 3;
							}
					}
					else if(MapArray[y][x].placed == true && MapArray[y][x].hit != true){
						MapArray[y][x].hit = true;
						MapArray[y][x].tileType = 4;
						lhY = y;
						cout << "\a";
						cout << "\a";
						cout << "\a";
						NumOfHits += 1;
						hSuc = true;
						}
					else if(MapArray[y][x].placed != true){
						MapArray[y][x].hit = true;
						MapArray[y][x].tileType = 3;
						cout << "\a";
						hSuc = true;
						}

			
				placeLoop = false;
				break;
		}//End of Switch
	}//End of While
}