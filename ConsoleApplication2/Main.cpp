// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni - DONE
// Vyresit handl az bude NPC funkcionalita - DONE
//vyresit u class public a private
//naucit se realne jak pouzivat reference in comparison to pointers
//unspaghettifi input, it's so ugly
//maybe put attack in a better place than in a nested entity_check in input? seems a lil unintuitive for
//code readers
//make add new entity work in NPC constructor
//windows metoda zneviditelnit cursor?
//V Y RE S I T K CEMU SE POUZIVAJI REFERENCE AAA!!!! DELA TOS TRASNE MOC BUGU KDYZ NEVIS JAK POUZIVAT

////pridavani entit skrze create metodu
//to je super napad
//abychom to 
//v pohybu mit metodu jenom move ktera se vola v inputu, zmensit spagetku
//input jen ma zpracovavat input a posilat ho dal, nema ho checkovat
//a delat s nim veci, to je na movement systemu (mozna udelat classu)

//dat const na mista

#include "Game.hpp"

int main(int argc, char* argv[])
{
	MainLoop game;
	game.run();

	return 0;
}