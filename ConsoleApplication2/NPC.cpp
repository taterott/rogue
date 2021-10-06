#pragma once

#include "NPC.hpp"

NonPlayerCharacter::NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health)
{
		this->npc_char = npc_char;
		this->name = name;
		this->x = x;
		this->y = y;
		this->health = health;
}

void Entities::addNewEntity(NonPlayerCharacter* entity_to_add) 
{
	npcs.push_back(entity_to_add);
}

void NonPlayerCharacter::gotoxy(int x, int y)
{
	if (theHandlNPC == nullptr)
	{
		theHandlNPC = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(theHandlNPC, cord);

}




void NonPlayerCharacter::moveNpc() {
	gotoxy(x, y);
	std::cout << '@';
}