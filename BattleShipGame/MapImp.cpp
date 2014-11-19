#include "ExtendedWin32Console.h"
#include "Map.h"
#include <conio.h>
#include <time.h>
#include <iostream>

using namespace std;

void Map::Loading(){
console.SetColor(155);
console.SetPosition(23 + 11 ,12);
cout << "Loading..." << endl;
}

void Map::unLoading(){
console.SetColor(0);
console.SetPosition(27 + 10 ,12);
cout << "          " << endl;
}

void Map::SetMap(){
	int i,j;
	for (i = 0; i < HEIGHT; i++){
		for(j = 0; j < WIDTH; j++){
			MapArray[i][j].tileType = 0;
			MapArray[i][j].hit = false;
			MapArray[i][j].placed = false;
			MapArray[i][j].tileName = "Water";
			}
	}
}

void Map::pDrawMap(){
	int i,j;
	console.SetPosition(25, 4);
		console.SetColor(11);
		cout << "Player Map ";

		console.SetPosition(25 + 17 + 18, 3);
		console.SetColor(11);
		cout << "How to Play " << endl;
		console.SetPosition(25 + 17 + 13, 4);
		cout << "Use the A, S, D, and W " << endl;
		console.SetPosition(25 + 17 + 13, 5);
		cout << "keys to move your ships " << endl;
		console.SetPosition(25 + 17 + 13, 6);
		cout << "and press enter to place " << endl;
		console.SetPosition(25 + 17 + 13, 7);
		cout << "them. Then use those " << endl;
		console.SetPosition(25 + 17 + 13, 8);
		cout << "keys to move around the " << endl;
		console.SetPosition(25 + 17 + 13, 9);
		cout << "cursor on the enemy map " << endl;
		console.SetPosition(25 + 17 + 13, 10);
		cout << "and hit enter to fire. " << endl;
		console.SetPosition(25 + 17 + 13, 11);
		cout << "First to hit all enemy " << endl;
		console.SetPosition(25 + 17 + 13, 12);
		cout << "ships wins. " << endl;

	for (i = 0; i < HEIGHT; i++){
		console.SetPosition(22,i + 6);
		for(j = 0; j < WIDTH; j++){
			if (MapArray[i][j].placed == false){
		 switch(MapArray[i][j].tileType){
			case 0:
				console.SetColor(155);
				console << '~';
				break;
			case 1:
				console.SetColor(154);
				console << '#';
				break;
			case 2:
				console.SetColor(151);
				console << '#';
				break;
			case 3:
				console.SetColor(197);
				console << '~';
				break;
			}
			}
			else{
				if (MapArray[i][j].hit != true){
				console.SetColor(151);
				console << '#';
				}
				else{
				console.SetColor(244);
				console << 'X';
				}
				}
		}
	}//end of for
	}

void Map::eDrawMap(){
	int i,j;
	console.SetPosition(25 + 17, 4);
		console.SetColor(11);
		cout << " Enemy Map ";
	for (i = 0; i < HEIGHT; i++){
		console.SetPosition(22 + 17,i + 6);
		for(j = 0; j < WIDTH; j++){
			if(MapArray[i][j].hit == false||MapArray[i][j].tileType == 1){
		switch(MapArray[i][j].tileType){
		 	case 0:
				console.SetColor(155);
				console << '~';
				break;
			case 1:
				console.SetColor(154);
				console << '#';
				break;
			case 2:
				console.SetColor(155);
				console << '~';
				break;
			
			}
			}
			else {
				if (MapArray[i][j].placed != true){
				console.SetColor(197);
				console << '~';
				}
				else{
				console.SetColor(244);
				console << 'X';
				}				
			}
		}
	}//end of for
	}



void Map::placeShips(Ship CShip, Map& CMap){
	int i,x = 0,y = 0;
	char bKey;
	bool placeLoop = true;
	for(i = 0; i < CShip.sqNum ; i++){
		MapArray[y + i][x].tileType = 1;
	}//end of for loop
	x = 0;
	y = 0;
	while(placeLoop){
			CMap.pDrawMap();
			bKey = getch();
		switch(bKey){
			case 'r':
				if (CShip.Alignment == 'v'){
				if (IsPassable(x + CShip.sqNum - 1, y)){
					CShip.Width = CShip.Height;
					CShip.Height = 1;
					CShip.Alignment = 'h';

					for(i = 0; i < CShip.sqNum; i++){
						MapArray[y + i][x].tileType = 0;
									}
					for(i = 0; i < CShip.sqNum; i++){
						MapArray[y][x + i].tileType = 1;
						}	
					}
				}
				else{
				if (IsPassable(x, y + CShip.sqNum - 1)){
					CShip.Height = CShip.sqNum;
					CShip.Width = 1;
					CShip.Alignment = 'v';

					for(i = 0; i < CShip.sqNum; i++){
						MapArray[y][x + i].tileType = 0;
									}
					for(i = 0; i < CShip.sqNum; i++){
						MapArray[y + i][x].tileType = 1;
						}	
					}
				}
				break;
			case 'w':
				if (CShip.Alignment == 'v'){//Vertical
					if (IsPassable(x, y - 1)){
					for(i = 0; i < CShip.Height; i++){
						MapArray[y + i][x].tileType = 0;
									}
					for(i = 0; i < CShip.Height; i++){
						MapArray[y - 1 + i][x].tileType = 1;
						}	
					y = y - 1;
					}
				 }
				else{ // Horizontal
					if (IsPassable(x, y - 1)){
					for(i = 0; i < CShip.Width; i++){
						MapArray[y][x + i].tileType = 0;
									}
					for(i = 0; i < CShip.Width; i++){
						MapArray[y - 1][x + i].tileType = 1;
						}	
					y = y - 1;
					}
				  }
				break;
			case 'd':
				if (CShip.Alignment == 'v'){//Vertical
					if (IsPassable(x + 1, y)){
					for(i = 0; i < CShip.Height; i++){
						MapArray[y + i][x].tileType = 0;
					}
					for(i = 0; i < CShip.Height; i++){
						MapArray[y + i][x + 1].tileType = 1;
					}
					x = x + 1;
					}
			   	  }
				else{ // Horizontal
					if (IsPassable(x + CShip.Width, y)){
					for(i = 0; i < CShip.Width; i++){
						MapArray[y][x + i].tileType = 0;
					}
					for(i = 0; i < CShip.Width; i++){
						MapArray[y][x + 1 + i].tileType = 1;
					}
					x = x + 1;
					}
					}
				break;
			case 'a': 
				if (CShip.Alignment == 'v'){//Vertical
					if (IsPassable(x - 1, y)){
					for(i = 0; i < CShip.Height; i++){
						MapArray[y + i][x].tileType = 0;
					}
					for(i = 0; i < CShip.Height; i++){
						MapArray[y + i][x - 1].tileType = 1;
					}
					x = x - 1;
					}
				  }
				else{ // Horizontal
					if (IsPassable(x - 1, y)){
						for(i = 0; i < CShip.Width; i++){
						MapArray[y][x + i].tileType = 0;
						}
						for(i = 0; i < CShip.Width; i++){
						MapArray[y][x - 1 + i].tileType = 1;
						}
					x = x - 1;
					}
				}////   maybe missing }
				break;
			case 's': 
				if (CShip.Alignment == 'v'){//Vertical
					if (IsPassable(x, y + CShip.Height)){
						for(i = 0; i < CShip.Height; i++){
							MapArray[y + i][x].tileType = 0;
						}
						for(i = 0; i < CShip.Height; i++){
							MapArray[y + 1 + i][x].tileType = 1;
							}
					y = y + 1;
					}
				}
				else{ // Horizontal
					if (IsPassable(x, y + 1)){
						for(i = 0; i < CShip.Width; i++){
							MapArray[y][x + i].tileType = 0;
						}
						for(i = 0; i < CShip.Width; i++){
							MapArray[y + 1][x + i].tileType = 1;
							}
					y = y + 1;
					}
				}
				break;
			case 13:
				if (IsPlaceable(CShip, x, y)){
				if (CShip.Alignment == 'v'){
				for(i = 0; i < CShip.sqNum; i++){
					MapArray[y + i][x].tileType = 2;
					MapArray[y + i][x].placed = true;
					MapArray[y + i][x].tileName = CShip.Name;

				}
				}
				if (CShip.Alignment == 'h'){
				for(i = 0; i < CShip.sqNum; i++){
					MapArray[y][x + i].tileType = 2;
					MapArray[y][x + i].placed = true;
					MapArray[y][x + i].tileName = CShip.Name;
				}
				}
				placeLoop = false;
				}//end of if placeable
				break;
		}//End of Switch
	}//End of While
}

void Map::rndShips(Ship CShip){
	int x;
	int y;
	int i;

	bool placeLoop = true;
	while(placeLoop){
		srand ( time(NULL) );
	x = rand() % 15 + 1;
	y = rand() % 10 + 1;	
	if (IsPlaceable(CShip, x, y)){
				if (CShip.Alignment == 'v'){
			for(i = 0; i < CShip.sqNum; i++){
				MapArray[y + i][x].tileType = 2;
				MapArray[y + i][x].placed = true;
				MapArray[y + i][x].tileName = CShip.Name;
			}
			}
			if (CShip.Alignment == 'h'){
			for(i = 0; i < CShip.sqNum; i++){
				MapArray[y][x + i].tileType = 2;
				MapArray[y][x + i].placed = true;
				MapArray[y][x + i].tileName = CShip.Name;
			}
			}
			placeLoop = false;
			}//end of if placeable
	}
	
}


bool Map::IsPassable(int MapX, int MapY)
{
	if( MapX < 0 || MapX >= WIDTH || MapY < 0 || MapY >= HEIGHT )
		return false;
	
	// If execution get's here, it's passable
	return true;
}

bool Map::IsPlaceable(Ship PShip, int MapX, int MapY){ 
	int i, x, y;
	x = MapX;
	y = MapY;
if( MapX < 0 || MapX >= WIDTH + PShip.Width || MapY < 0 || MapY + PShip.Height - 1 >= HEIGHT )
		return false;

if (PShip.Alignment == 'v'){//Vertical
	
				for(i = 0; i < PShip.Height; i++){
						if (MapArray[y + i][x].placed == true)
						return false;
				 }
}
else{ // Horizontal
					
				for(i = 0; i < PShip.Width; i++){
						if (MapArray[y][x + i].placed == true)
						return false;
				}

}
return true;
}