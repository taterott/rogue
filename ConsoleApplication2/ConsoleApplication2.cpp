// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni
//dat const na mista

#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>

#define ROWS 25
#define COLUMNS 25

/*useful characters to have:

interpunct: '·' - this is for normal ground
overline: ‾: 
*/

/*
								                                 
 __     __
|  |--.|__|.-----.-----.--.--.-----.
|  _  ||  ||     |  _  |  |  |__ --|
|_____||__||__|__|___  |_____|_____|
				 |_____|


*/

HANDLE theHandl = nullptr;

void gotoxy(int x, int y)
{
	if (theHandl == nullptr)
	{
		theHandl = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(theHandl, cord);
}

class Player
{
public:
	Player() {};
	~Player() {};
	char playerChar = '@';
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int health = 4;
	int attack = 1;

	void movePlayer() {
		gotoxy(x, y);
		std::cout << '@';
	}

	//void attackNpc(int target_x, int target_y, NonPlayerCharacter npc) {

	//}
private:
};

class NonPlayerCharacter
{
	NonPlayerCharacter() {};
	~NonPlayerCharacter() {};
	char npcChar = 'Ω';
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int health = 3;
private:

};

//class Entities
//{
//public:
//	Entities() {};
//	~Entities() {};
//
//	void addNewEntity(std::string name) {
//		NonPlayerCharacter name;
//
//	}
//	std::vector<NonPlayerCharacter> npcs;
//
//	int num_of_npcs = 0;
//};




class WorldMap
{
public:
	WorldMap() {};
	~WorldMap() {};

	void printMap()
	{
		for(int n = 0; n < ROWS; n++) {
			for (int m = 0; m < COLUMNS ; m++) {
				std::cout << tilesActive[n][m];
			}
			std::cout << std::endl;
		}
	}
 
	//void setTile(char character, int row, int column, int prev_row, int prev_column)
	//{
	//	tilesActive[prev_row][prev_column] = tilesBase[prev_row][prev_column];
	//	tilesActive[row][column] = character;
	//}

	int checkWallCollision(int dest_x, int dest_y) {
		if (tilesBase[dest_y][dest_x] != '.') {
			return 0;
		}
		else
		{
			return 1;
		}
	}

	void loadMapFromTxt(std::string map_location) {
		std::fstream map;
		map.open(map_location, std::ios::in);

		if (!map) {
			std::cout << "Couldn't find map file of that name" << std::endl;
		}
		else
		{
			std::getline(map, mapString, 'G');
		}

		convertMap();

		map.close();
	}

	void convertMap() {
		int rowPosition = 0;
		int columnPosition = 0;
		int stringPosition = 0;

		while (rowPosition < ROWS) {
			for (columnPosition; columnPosition < COLUMNS; columnPosition++) {
				if (mapString[stringPosition] == '\n') {
					break;
				}else {
					tilesBase[rowPosition][columnPosition] = mapString[stringPosition];
					tilesActive[rowPosition][columnPosition] = mapString[stringPosition];
				}
				stringPosition++;
			}
			rowPosition++;
			stringPosition++;
			columnPosition = 0;
		}
	}

	void printStringMap() {
		std::cout << mapString;
	}

private:

	const int rows = ROWS;
	const int columns = COLUMNS;
	char tilesActive[ROWS][COLUMNS];

	char tilesBase[ROWS][COLUMNS];

	std::string mapString;
};

class Input
{
public:
	Input() {};
	~Input() {};


	//kdyby mapa a hrac nebyly reference/pointery (ale pak bych musel udelat hrac->x misto hrac.x
	void PlayerMovement(WorldMap &mapa, Player &hrac)
	{
		char input = _getch();


		switch (input) {
		case '8':
			//collision for walls
			if (mapa.checkWallCollision(hrac.x, hrac.y - 1) == 0) { break; }
			//out of bounds for up
			if (hrac.y > 0) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.y--;
			}
			break;
		case '9':
			if (mapa.checkWallCollision(hrac.x + 1, hrac.y - 1) == 0) { break; }
			//out of bounds for up
			if ((hrac.x + 1 < COLUMNS) && (hrac.y > 0)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
				hrac.y--;
			}
			break;
		case '6':
			if (mapa.checkWallCollision(hrac.x + 1, hrac.y) == 0) { break; }
			//out of bounds for right
			if (hrac.x + 1 < COLUMNS) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
			}
			break;
		case '3':
			if (mapa.checkWallCollision(hrac.x + 1, hrac.y + 1) == 0) { break; }
			//out of bounds for up
			if ((hrac.x + 1 < COLUMNS) && (hrac.y + 1 < ROWS)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
				hrac.y++;
			}
			break;
		case '4':
			if (mapa.checkWallCollision(hrac.x - 1, hrac.y) == 0) { break; }
			//out of bounds for left
			if (hrac.x > 0) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
			}
			break;
		case '2':
			if (mapa.checkWallCollision(hrac.x, hrac.y + 1) == 0) { break; }
			//out of bounds for down
			if (hrac.y + 1 < ROWS) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.y++;
			}
			break;
		case '1':
			if (mapa.checkWallCollision(hrac.x - 1, hrac.y + 1) == 0) { break; }
			if ((hrac.x > 0) && (hrac.y + 1 < ROWS)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
				hrac.y++;
			}
			break;
		case '7':
			if (mapa.checkWallCollision(hrac.x - 1, hrac.y - 1) == 0) { break; }
			if ((hrac.x > 0) && (hrac.y > 0)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
				hrac.y--;
			}
			break;
		}
	}

};


int main()
{
	Player hrac;
	WorldMap mapa;
	Input input;

	mapa.loadMapFromTxt("map.txt");

	while (true)
	{
		system("CLS");

		mapa.printMap();
		hrac.movePlayer();
		input.PlayerMovement(mapa, hrac);
		
		std::cout.flush();

		//debugging couts for player coordinates
		//std::cout << "CURRENT: " << protag.x << "," << protag.y << std::endl;
		//std::cout << "PREV: " <<  hrac.prev_x << "," << hrac.prev_y << std::endl;
	}


	//zjistit proc ty previous veci nefungujou bez davani prev_x  = x i kdyz se hybeme jen na y
	return 0;

}