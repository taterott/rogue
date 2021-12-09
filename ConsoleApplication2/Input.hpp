#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "WorldMap.hpp"
#include "Text.hpp"

class Input
{
public:
	//kdyby mapa a hrac nebyly reference/pointery (ale pak bych musel udelat hrac->x misto hrac.x
	void player_movement(WorldMap& mapa, Player& hrac, Entities& entity_list, Text& text_log);

	char recent_input = '0';
};
