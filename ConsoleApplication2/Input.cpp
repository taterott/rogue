#include "Input.hpp"

void Input::PlayerMovement(WorldMap& mapa, Player& hrac)
{
	char input = _getch();


	switch (input) {
	case '8':
		//collision for walls
		if (mapa.checkWallCollision(hrac.x, hrac.y - 1) == 0) { break; }
		//out of bounds for up
		if (hrac.y > 0) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.y--;
		}
		break;
	case '9':
		if (mapa.checkWallCollision(hrac.x + 1, hrac.y - 1) == 0) { break; }
		//out of bounds for up
		if ((hrac.x + 1 < COLUMNS) && (hrac.y > 0)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
			hrac.y--;
		}
		break;
	case '6':
		if (mapa.checkWallCollision(hrac.x + 1, hrac.y) == 0) { break; }
		//out of bounds for right
		if (hrac.x + 1 < COLUMNS) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
		}
		break;
	case '3':
		if (mapa.checkWallCollision(hrac.x + 1, hrac.y + 1) == 0) { break; }
		//out of bounds for up
		if ((hrac.x + 1 < COLUMNS) && (hrac.y + 1 < ROWS)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
			hrac.y++;
		}
		break;
	case '4':
		if (mapa.checkWallCollision(hrac.x - 1, hrac.y) == 0) { break; }
		//out of bounds for left
		if (hrac.x > 0) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
		}
		break;
	case '2':
		if (mapa.checkWallCollision(hrac.x, hrac.y + 1) == 0) { break; }
		//out of bounds for down
		if (hrac.y + 1 < ROWS) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.y++;
		}
		break;
	case '1':
		if (mapa.checkWallCollision(hrac.x - 1, hrac.y + 1) == 0) { break; }
		if ((hrac.x > 0) && (hrac.y + 1 < ROWS)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
			hrac.y++;
		}
		break;
	case '7':
		if (mapa.checkWallCollision(hrac.x - 1, hrac.y - 1) == 0) { break; }
		if ((hrac.x > 0) && (hrac.y > 0)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
			hrac.y--;
		}
		break;
	}
}