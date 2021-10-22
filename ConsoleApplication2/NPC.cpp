#pragma once

#include "NPC.hpp"

extern HANDLE the_handle = nullptr;

NonPlayerCharacter::NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health, Entities entity_list)
{
		this->npc_char = npc_char;
		this->name = name;
		this->x = x;
		this->y = y;
		this->health = health;
		this->entity_index = entity_list.num_of_npcs;
		//entity_list.add_new_entity(this);
}

void Entities::add_new_entity(NonPlayerCharacter* entity_to_add) 
{
	npcs.push_back(entity_to_add);
	num_of_npcs++;
}

//returns index of NPC at coordinates X and Y (if any
//exists at such coordinates), if not, returns -1
int Entities::find_entity_thru_coords(int x, int y)
{
	for (int index = 0; index < npcs.size(); index++)
	{
		if (npcs[index]->x == x && npcs[index]->y == y)
		{
			return index;
		}
	}
	return -1;
}

void NonPlayerCharacter::go_to_xy(int x, int y)
{

	if (the_handle == nullptr)
	{
		the_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(the_handle, cord);

}




void NonPlayerCharacter::move_npc() {
	go_to_xy(x, y);
	std::cout << npc_char;
}