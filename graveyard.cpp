// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// REFAKTORNOUT TEN KOD aby to bylo nejak funkcni
// udelat NPC s dialogem
// udelat loadovni mapy ze souboru?
// inventar?

#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vector>
#include <fstream>

#define ROWS 25
#define COLUMNS 25

void convertStringToMatrix() {

	int stringIndex = 0;
	int stringMultiplier = 1;
	int numOfNewlines = 0;
	bool firstLoop = true;



	for (int x = 0; x < ROWS; x++) {
		if (x >= 1) { firstLoop = false; }
		for (int y = 0; y < COLUMNS; x++) {

			if (mapString[y] == '\n') {
				numOfNewlines++;
			}

			if (firstLoop) {
				tilesActive[x][y] = mapString[y];
			}
			else {
				int trueIndex = (x * y) + numOfNewlines;
				tilesActive[x][trueIndex];
			}



		}
	}
}



//input.PlayerMovement(tiles, protag);

//char input = _getch();

//switch (input) {
//case '8':
//	//collision for walls
//	if (mapa.checkWallCollision(hrac.x, hrac.y-1) == 0) { break; }
//	//out of bounds for up
//	if (hrac.y > 0) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.y--;
//	}
//	break;
//case '9':
//	if (mapa.checkWallCollision(hrac.x+1, hrac.y-1) == 0) { break; }
//	//out of bounds for up
//	if ((hrac.x + 1 < COLUMNS) && (hrac.y > 0)) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x++;
//		hrac.y--;
//	}
//	break;
//case '6':
//	if (mapa.checkWallCollision(hrac.x+1, hrac.y) == 0) { break; }
//	//out of bounds for right
//	if (hrac.x + 1 < COLUMNS) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x++;
//	}
//	break;
//case '3':
//	if (mapa.checkWallCollision(hrac.x+1, hrac.y+1) == 0) { break; }
//	//out of bounds for up
//	if ((hrac.x + 1 < COLUMNS) && (hrac.y + 1 < ROWS)) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x++;
//		hrac.y++;
//	}
//	break;
//case '4':
//	if (mapa.checkWallCollision(hrac.x-1, hrac.y) == 0) { break; }
//	//out of bounds for left
//	if (hrac.x > 0) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x--;
//	}
//	break;
//case '2':
//	if (mapa.checkWallCollision(hrac.x, hrac.y+1) == 0) { break; }
//	//out of bounds for down
//	if (hrac.y + 1 < ROWS) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.y++;
//	}
//	break;
//case '1':
//	if (mapa.checkWallCollision(hrac.x-1, hrac.y+1) == 0) { break; }
//	if ((hrac.x > 0) && (hrac.y + 1 < ROWS)) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x--;
//		hrac.y++;
//	}
//	break;
//case '7':
//	if (mapa.checkWallCollision(hrac.x-1, hrac.y-1) == 0) { break; }
//	if ((hrac.x > 0) && (hrac.y > 0)) {
//		hrac.prev_x = hrac.x;
//		hrac.prev_y = hrac.y;
//		hrac.x--;
//		hrac.y--;
//	}
//	break;
//}
