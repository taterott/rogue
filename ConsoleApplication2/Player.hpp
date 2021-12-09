#pragma once

#include "NPC.hpp"
#include "Text.hpp"

class Player : public BasicEntity
{
public:
	//HANDLE theHandl = nullptr;
	void attack(int x, int y, Entities& entity_list, Text& text_log);

	char player_char = '@';
	int health = 4;
	int damage = 1;

	void move_player();
	
	friend class NonPlayerCharacter;
	friend class Entities;
};