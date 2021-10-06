// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni
//dat const na mista

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "Player.hpp"
#include "WorldMap.hpp"
#include "Input.hpp"
#include "NPC.hpp"

#define ROWS 25
#define COLUMNS 25

/*useful characters to have:

interpunct: '·' - this is for normal ground
overline: ‾:
*/

/*

 __     __
|  |--.|__|.-----.-----.--.--.-----.
|  _  ||  ||     |  _  |  |  |__ --|
|_____||__||__|__|___  |_____|_____|
				 |_____|


*/
//class NonPlayerCharacter
//{
//public:
//	NonPlayerCharacter(char npc_char, std::string name, int x, int y, int health)
//	{
//		this->npc_char = npc_char;
//		this->name = name;
//		this->x = x;
//		this->y = y;
//		this->health = health;
//	}
//private:
//	char npc_char = 'Ω';
//	std::string name;
//	int x = 0;
//	int y = 0;
//	int prev_x = 0;
//	int prev_y = 0;
//	int health = 3;
//	bool enemy = false;
//};
//
//class Entities
//{
//public:
//	Entities() {};
//	~Entities() {};
//
//	void addNewEntity(NonPlayerCharacter * entity_to_add){
//		npcs.push_back(entity_to_add);
//	}
//	std::vector<NonPlayerCharacter*> npcs;
//
//	int num_of_npcs = 0;
//};

int main()
{
	Player hrac;
	WorldMap mapa;
	Input input;
	Entities entity;
	//kdyz dam new tak to vraci pointer, kdyz bez new tak to vraci ten objekt;
	auto *npcko = new NonPlayerCharacter('Δ', "Delta", 12, 12, 3);
	entity.addNewEntity(npcko);
	

	mapa.loadMapFromTxt("map.txt");

	while (true)
	{
		system("CLS");

		mapa.printMap();
		hrac.movePlayer();
		input.PlayerMovement(mapa, hrac);

		std::cout.flush();

		//debugging couts for player coordinates
		//std::cout << "CURRENT: " << protag.x << "," << protag.y << std::endl;
		//std::cout << "PREV: " <<  hrac.prev_x << "," << hrac.prev_y << std::endl;
	}


	//zjistit proc ty previous veci nefungujou bez davani prev_x  = x i kdyz se hybeme jen na y
	return 0;

}