#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Generic.cpp"

class NonPlayerCharacter;

class Entities
{
public:
	Entities() {};
	~Entities() {};

	void add_new_entity(NonPlayerCharacter* entity_to_add);
	int find_entity_thru_coords(int x, int y);

	//do non pointer, but maybe a linked list woudl be better whenit comes
	//to a lot of things
	//just do an is_deleted parameter on npcs and not mess 
	//
	std::vector<NonPlayerCharacter*> npcs;

	int num_of_npcs = 0;
private:
};

class NonPlayerCharacter
{
public:

	NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health, Entities entity_list);
	void move_npc();
	void go_to_xy(int x, int y);
	char npc_char = 'ﬡ';

	void check_death() 
	{
		if (current_health <= health) {
			free(this);
		}
	}
	std::string name;
	int x = 3;
	int y = 3;
	int prev_x = 0;
	int prev_y = 0;
	int health = 3;
	int current_health = health;
	bool enemy = false;
	int entity_index;

	friend class Entities;



};
