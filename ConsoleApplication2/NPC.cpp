#pragma once
//IF YOU PASS ANYTHING NOT AS A PONTER OR A REFERENCE ITS GETTING COPIED
#include "NPC.hpp"

extern HANDLE the_handle = nullptr;

NonPlayerCharacter::NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health,
	bool hostile)
{
		this->npc_char = npc_char;
		this->name = name;
		this->x = x;
		this->y = y;
		this->health = health;
		this->current_health = health;
		this->enemy = hostile;
		this->test_greeting = "Hey, I'm " + name + ". Watch where you're going!";
		load_dialogue();
}

//NonPlayerCharacter::~NonPlayerCharacter()
//{
//
//}

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

void BasicEntity::go_to_xy(int x, int y)
{

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(the_handle, cord);

}




int NonPlayerCharacter::move_npc() 
{
	if (death)
	{
		return 0;
	}
	else
	{
		go_to_xy(x, y);
		std::cout << npc_char;
		return 1;
	}
}

void NonPlayerCharacter::check_death()
{
	if (current_health <= health) {
		death = true;
	}
}

void NonPlayerCharacter::load_dialogue()
{
	npc_dialogue.load_dialogue_from_text(name + ".txt");
}

//void NonPlayerCharacter::load_dialogue_from_txt(std::string dialogue_location)
//{
//	std::fstream dialogue;
//	dialogue.open(dialogue_location, std::ios::in);
//
//	if (!dialogue)
//	{
//		std::cout << "Couldn't find map file of that name" << std::endl;
//	}
//	else
//	{
//		std::getline(map, map_string, 'G');
//	}
//
//	convert_map();
//
//	map.close();
//}

void Entities::dealloc_entities()
{
	for (int i = 0; i < npcs.size(); i++)
	{
		delete npcs[i];
	}
}

void Entities::move_all_entities()
{
	for (int i = 0; i < npcs.size(); i++)
	{
		npcs[i]->move_npc();
	}
}

void Entities::create_npc(char npc_char, std::string name, int x, int y, int health,
	bool hostile)
{
	NonPlayerCharacter* new_npc = new NonPlayerCharacter(npc_char, name, x, y, health,
		hostile);
	this->add_new_entity(new_npc);
}
