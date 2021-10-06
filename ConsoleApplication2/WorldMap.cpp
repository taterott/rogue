#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "Player.hpp"
#include "WorldMap.hpp"

void WorldMap::printMap()
{
	for (int n = 0; n < ROWS; n++) {
		for (int m = 0; m < COLUMNS; m++) {
			std::cout << tilesActive[n][m];
		}
		std::cout << std::endl;
	}
}

int WorldMap::checkWallCollision(int dest_x, int dest_y) 
{
	if (tilesBase[dest_y][dest_x] != '.') {
		return 0;
	}
	else
	{
		return 1;
	}
}

void WorldMap::loadMapFromTxt(std::string map_location)
{
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

void WorldMap::printStringMap()

{
		std::cout << mapString;
}


void WorldMap::convertMap()
{
	int rowPosition = 0;
	int columnPosition = 0;
	int stringPosition = 0;

	while (rowPosition < ROWS) {
		for (columnPosition; columnPosition < COLUMNS; columnPosition++) {
			if (mapString[stringPosition] == '\n') {
				break;
			}
			else {
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


