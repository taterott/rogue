#pragma once

#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>

class NonPlayerCharacter
{
public:

	HANDLE theHandlNPC = nullptr;

	NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health);
	void moveNpc();
	void gotoxy(int x, int y);
private:
	char npc_char = 'Ω';
	std::string name;
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int health = 3;
	bool enemy = false;
};

class Entities
{
public:
	Entities() {};
	~Entities() {};

	void addNewEntity(NonPlayerCharacter* entity_to_add);
	std::vector<NonPlayerCharacter*> npcs;

	int num_of_npcs = 0;
};