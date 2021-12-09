//// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni - DONE
//// Vyresit handl az bude NPC funkcionalita - DONE
////vyresit u class public a private
////naucit se realne jak pouzivat reference in comparison to pointers
////unspaghettifi input, it's so ugly
////maybe put attack in a better place than in a nested entity_check in input? seems a lil unintuitive for
////code readers
////make add new entity work in NPC constructor
////windows metoda zneviditelnit cursor?
////V Y RE S I T K CEMU SE POUZIVAJI REFERENCE AAA!!!! DELA TOS TRASNE MOC BUGU KDYZ NEVIS JAK POUZIVAT
//
////dat const na mista
//
//#include <iostream>
//#include <string>
//#include <conio.h>
//#include <stdlib.h>
//#include <vector>
//#include <fstream>
//#include "Input.hpp"
//
//
///*useful characters to have:
//
//interpunct: '·' - this is for normal ground
//overline: ‾:
//*/
//
///*
//
//
//STYLE RULES:s
//1. Use snake_case, except for class names, use PascalCase for those
//
//*/
//
//int main()
//{
//	Player hrac;
//	WorldMap mapa;
//	Input input;
//	Entities entity;
//	Text text_log;
//
//	//kdyz dam new tak to vraci pointer, kdyz bez new tak to vraci ten objekt;
//	auto npcko = new NonPlayerCharacter('E', "Delta", 3, 3, 2, true, entity);
//	auto npcko2 = new NonPlayerCharacter('F', "Filip", 1, 9, 3, false, entity);
//	auto npcko3 = new NonPlayerCharacter('J', "Flungus", 22, 24, 10, true, entity);
//	auto npcko4 = new NonPlayerCharacter('K', "Bingus", 21, 24, 10, false, entity);
//	auto npcko5 = new NonPlayerCharacter('L', "kittykat", 23, 24, 10, true, entity);
//
//	entity.add_new_entity(npcko);
//	entity.add_new_entity(npcko2);
//	entity.add_new_entity(npcko3);
//	entity.add_new_entity(npcko4);
//	entity.add_new_entity(npcko5);
//
//	mapa.load_map_from_txt("map.txt");
//
//	//main game loop
//	while (true)
//	{
//		std::cout.flush();
//		system("CLS");
//		mapa.print_map();
//		text_log.render_log();
//		hrac.move_player();
//		npcko->move_npc();
//		npcko2->move_npc();
//		npcko3->move_npc();
//		npcko4->move_npc();
//		npcko5->move_npc();
//		input.player_movement(mapa, hrac, entity, text_log);
//
//		if (input.recent_input == 'q')
//		{
//			break;
//		}
//	}
//
//	std::cout << "Game shutdown." << std::endl;
//
//	entity.dealloc_entities();
//
//	std::cout << "This is NPC health, should display random number" << npcko->health << std::endl;
//
//	//zjistit proc ty previous veci nefungujou bez davani prev_x  = x i kdyz se hybeme jen na y
//	return 0;
//
//}