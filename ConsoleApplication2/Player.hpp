#pragma once

#include "NPC.hpp"

class Player
{
public:
	//HANDLE theHandl = nullptr;

	Player() {};
	~Player() {};

	void attack(int x, int y, Entities entity_list);

	char player_char = '@';
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int health = 4;
	int damage = 1;

	void move_player();
	void go_to_xy(int x, int y);
	
	friend class NonPlayerCharacter;
	friend class Entities;
};