#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "Player.hpp"

#define ROWS 25
#define COLUMNS 25

class WorldMap
{
public:
	WorldMap() {};
	~WorldMap() {};

	void printMap();
	//void setTile(char character, int row, int column, int prev_row, int prev_column)
	//{
	//	tilesActive[prev_row][prev_column] = tilesBase[prev_row][prev_column];
	//	tilesActive[row][column] = character;
	//}

	int checkWallCollision(int dest_x, int dest_y);

	void loadMapFromTxt(std::string map_location);

	void convertMap();

	void printStringMap();

private:

	const int rows = ROWS;
	const int columns = COLUMNS;
	char tilesActive[ROWS][COLUMNS];

	char tilesBase[ROWS][COLUMNS];

	std::string mapString;
};