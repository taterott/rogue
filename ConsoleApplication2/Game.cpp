// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni - DONE
// Vyresit handl az bude NPC funkcionalita
//vyresit u class public a private
//naucit se realne jak pouzivat reference in comparison to pointers
//unspaghettifi input, it's so ugly
//maybe put attack in a better place than in a nested entity_check in input? seems a lil unintuitive for
//code readers
//make add new entity work in NPC constructor

//dat const na mista

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Input.hpp"


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


STYLE RULES:
1. Use snake_case, except for class names, use PascalCase for those

*/

int main()
{
	Player hrac;
	WorldMap mapa;
	Input input;
	Entities entity;
	//kdyz dam new tak to vraci pointer, kdyz bez new tak to vraci ten objekt;

	auto npcko = new NonPlayerCharacter('E', "Delta", 3, 3, 2, entity);
	auto npcko2 = new NonPlayerCharacter('F', "Filip", 1, 9, 3, entity);
	auto npcko3 = new NonPlayerCharacter('X', "Tomas", 1, 10, 4, entity);



	entity.add_new_entity(npcko);
	entity.add_new_entity(npcko2);
	entity.add_new_entity(npcko3);
	

	mapa.load_map_from_txt("map.txt");

	//main game loop
	while (true)
	{
		system("CLS");

		mapa.print_map();
		hrac.move_player();
		npcko->move_npc();
		npcko2->move_npc();
		npcko3->move_npc();
		input.player_movement(mapa, hrac, entity);

		std::cout.flush();

		//debugging couts for player coordinates
		//std::cout << "CURRENT: " << protag.x << "," << protag.y << std::endl;
		//std::cout << "PREV: " <<  hrac.prev_x << "," << hrac.prev_y << std::endl;
	}


	//zjistit proc ty previous veci nefungujou bez davani prev_x  = x i kdyz se hybeme jen na y
	return 0;

}