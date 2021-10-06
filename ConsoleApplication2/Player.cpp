#include "Player.hpp"
#include <iostream>

void Player::gotoxy(int x, int y)
{
	if (theHandl == nullptr)
	{
		theHandl = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(theHandl, cord);
}

void Player::movePlayer() {
	gotoxy(x, y);
	std::cout << '@';
}