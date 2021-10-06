#pragma once

#include <Windows.h>


class Player
{
public:
	HANDLE theHandl = nullptr;

	Player() {};
	~Player() {};

	char playerChar = '@';
	int x = 0;
	int y = 0;
	int prev_x = 0;
	int prev_y = 0;
	int health = 4;
	int attack = 1;

	void movePlayer();
	void gotoxy(int x, int y);
};