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
#include "WorldMap.hpp"

class Input
{
public:
	Input() {};
	~Input() {};


	//kdyby mapa a hrac nebyly reference/pointery (ale pak bych musel udelat hrac->x misto hrac.x
	void PlayerMovement(WorldMap& mapa, Player& hrac);

};
