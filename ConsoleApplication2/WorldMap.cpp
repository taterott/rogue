#include "WorldMap.hpp"

void WorldMap::print_map()
{
	for (int n = 0; n < ROWS; n++) 
	{
		for (int m = 0; m < COLUMNS; m++)
		{
			std::cout << tiles_active[n][m];
		}
		std::cout << std::endl;
	}
}

int WorldMap::check_wall_collision(int dest_x, int dest_y) 
{
	if (tiles_base[dest_y][dest_x] != '.') 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void WorldMap::load_map_from_txt(std::string map_location)
{
	get_string_from_file(map_location, map_string);
	convert_map();

}

void WorldMap::print_string_map()

{
		std::cout << map_string;
}


void WorldMap::convert_map()
{
	int row_position = 0;
	int column_position = 0;
	int string_position = 0;

	while (row_position < ROWS) 
	{
		for (column_position; column_position < COLUMNS; column_position++)
		{
			if (map_string[string_position] == '\n')
			{
				break;
			}
			else
			{
				tiles_base[row_position][column_position] = map_string[string_position];
				tiles_active[row_position][column_position] = map_string[string_position];
			}
			string_position++;
		}
		row_position++;
		string_position++;
		column_position = 0;
	}
}


