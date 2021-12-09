#include "Input.hpp"
//OK SO WHTA IM DOING IS IM CHECKING IM ONLY ATTACKING IF THERE SI AN ENEMY ON A NON . PLACE

void Input::player_movement(WorldMap& mapa, Player& hrac, Entities& entity_list, Text& text_log)
{
	char input = _getch();


	if (input == 'q') {
		recent_input = input;
	}

	else {
		switch (input) {
		case '8':
			if (entity_list.find_entity_thru_coords(hrac.x, hrac.y - 1) != -1)
			{
				hrac.attack(hrac.x, hrac.y - 1, entity_list, text_log);
				recent_input = input;
				break;
			}
			//collision for walls
			else if (mapa.check_wall_collision(hrac.x, hrac.y - 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for up
			if (hrac.y > 0) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.y--;
			}
			recent_input = input;
			break;
		case '9':
			if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y - 1) != -1)
			{
				hrac.attack(hrac.x + 1, hrac.y - 1, entity_list, text_log);
				recent_input = input;
				break;
			}
			else if (mapa.check_wall_collision(hrac.x + 1, hrac.y - 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for up
			if ((hrac.x + 1 < COLUMNS) && (hrac.y > 0)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
				hrac.y--;
			}
			recent_input = input;
			break;
		case '6':
			if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y) != -1)
			{
				hrac.attack(hrac.x + 1, hrac.y, entity_list, text_log);
				 recent_input = input;
				break;
			}
			else if (mapa.check_wall_collision(hrac.x + 1, hrac.y) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for right
			if (hrac.x + 1 < COLUMNS) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
			}
			recent_input = input;
			break;
		case '3':
			if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y + 1) != -1)
			{
				hrac.attack(hrac.x + 1, hrac.y + 1, entity_list, text_log);
				recent_input = input;
				break;
			}

			else if (mapa.check_wall_collision(hrac.x + 1, hrac.y + 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for up
			if ((hrac.x + 1 < COLUMNS) && (hrac.y + 1 < ROWS)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x++;
				hrac.y++;
			}
			recent_input = input;
			break;
		case '4':

			if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y) != -1)
			{
				hrac.attack(hrac.x - 1, hrac.y, entity_list, text_log);
				recent_input = input;
				break;
			}

			else if (mapa.check_wall_collision(hrac.x - 1, hrac.y) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for left
			if (hrac.x > 0) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
			}
			recent_input = input;
			break;
		case '2':
			if (entity_list.find_entity_thru_coords(hrac.x, hrac.y + 1) != -1)

			{
				hrac.attack(hrac.x, hrac.y + 1, entity_list, text_log);
				recent_input = input;
				break;
			}

			else if (mapa.check_wall_collision(hrac.x, hrac.y + 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}
			//out of bounds for down
			if (hrac.y + 1 < ROWS) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.y++;
			}
			recent_input = input;
			break;
		case '1':

			if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y + 1) != -1)
			{
				hrac.attack(hrac.x - 1, hrac.y + 1, entity_list, text_log);
				recent_input = input;
				break;
			}

			else if (mapa.check_wall_collision(hrac.x - 1, hrac.y + 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}

			if ((hrac.x > 0) && (hrac.y + 1 < ROWS)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
				hrac.y++;
			}
			recent_input = input;
			break;
		case '7':

			if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y - 1) != -1)
			{
				hrac.attack(hrac.x - 1, hrac.y - 1, entity_list, text_log);
				recent_input = input;
				break;
			}

			else if (mapa.check_wall_collision(hrac.x - 1, hrac.y - 1) == 0)
			{
				Beep(120, 100);
				recent_input = input;
				break;
			}

			if ((hrac.x > 0) && (hrac.y > 0)) {
				hrac.prev_x = hrac.x;
				hrac.prev_y = hrac.y;
				hrac.x--;
				hrac.y--;
			}
			recent_input = input;
			break;
		}
	}
}