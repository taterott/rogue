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

	void print_map();
	//void setTile(char character, int row, int column, int prev_row, int prev_column)
	//{
	//	tilesActive[prev_row][prev_column] = tilesBase[prev_row][prev_column];
	//	tilesActive[row][column] = character;
	//}

	int check_wall_collision(int dest_x, int dest_y);

	void load_map_from_txt(std::string map_location);

	void convert_map();

	void print_string_map();

	const int rows = ROWS;
	const int columns = COLUMNS;
	char tiles_active[ROWS][COLUMNS];

	char tiles_base[ROWS][COLUMNS];

	std::string map_string;
};