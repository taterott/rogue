#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Generic.hpp"
#include <fstream>

class NonPlayerCharacter;

class Entities
{
public:
	void create_npc(char npc_char, std::string name, int x, int y, int health,
		bool hostile);
	void add_new_entity(NonPlayerCharacter* entity_to_add);
	int find_entity_thru_coords(int x, int y);
	void move_all_entities();
	void dealloc_entities();

	//do non pointer, but maybe a linked list woudl be better whenit comes
	//to a lot of things
	//just do an is_deleted parameter on npcs and not mess 
	//
	std::vector<NonPlayerCharacter*> npcs;

	int num_of_npcs = 0;


};

//pridavani entit skrze create metodu
//to je super napad
//abychom to 
class BasicEntity
{
public:

	void go_to_xy(int x, int y);

	std::string name;

	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
};

class NonPlayerCharacter : public BasicEntity
{
public:
	NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health,
		bool hostile);
	char npc_char = 'A';
	int move_npc();
	void check_death();
	//void load_dialogue_from_txt(std::string dialogue_location);
	int health = 3;
	int current_health = 1;
	bool enemy = false;
	int entity_index = 0;

	std::string test_greeting;

	//Dialogue npc_dialogue;

	bool death = false;

	friend class Entities;



};
