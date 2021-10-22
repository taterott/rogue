#include "Input.hpp"
//OK SO WHTA IM DOING IS IM CHECKING IM ONLY ATTACKING IF THERE SI AN ENEMY ON A NON . PLACE

void Input::player_movement(WorldMap& mapa, Player& hrac, Entities& entity_list)
{
	char input = _getch();


	switch (input) {
	case '8':
		if (entity_list.find_entity_thru_coords(hrac.x, hrac.y - 1) != -1)
		{
			hrac.attack(hrac.x, hrac.y - 1, entity_list);
			break;
		}
		//collision for walls
		else if (mapa.check_wall_collision(hrac.x, hrac.y - 1) == 0) 
		{ 
			break; 
		}
		//out of bounds for up
		if (hrac.y > 0) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.y--;
		}
		break;
	case '9':
		if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y - 1) != -1)
		{
			hrac.attack(hrac.x + 1, hrac.y - 1, entity_list);
			break;
		}
		else if (mapa.check_wall_collision(hrac.x + 1, hrac.y - 1) == 0) 
			{
				break;
			}
		//out of bounds for up
		if ((hrac.x + 1 < COLUMNS) && (hrac.y > 0)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
			hrac.y--;
		}
		break;
	case '6':
		if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y) != -1)
		{
			hrac.attack(hrac.x + 1, hrac.y, entity_list);
			break;
		}
		else if (mapa.check_wall_collision(hrac.x + 1, hrac.y) == 0) 
			{
				break;
			}
		//out of bounds for right
		if (hrac.x + 1 < COLUMNS) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
		}
		break;
	case '3':
		if (entity_list.find_entity_thru_coords(hrac.x + 1, hrac.y + 1) != -1)
		{
			hrac.attack(hrac.x + 1, hrac.y + 1, entity_list);
			break;
		}

		else if (mapa.check_wall_collision(hrac.x + 1, hrac.y + 1) == 0)
			{
				break;
			}
		//out of bounds for up
		if ((hrac.x + 1 < COLUMNS) && (hrac.y + 1 < ROWS)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x++;
			hrac.y++;
		}
		break;
	case '4':

		if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y) != -1)
		{
			hrac.attack(hrac.x - 1, hrac.y, entity_list);
			break;
		}

		else if (mapa.check_wall_collision(hrac.x - 1, hrac.y) == 0)
			{
				break;
			}
		//out of bounds for left
		if (hrac.x > 0) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
		}
		break;
	case '2':
		if (entity_list.find_entity_thru_coords(hrac.x, hrac.y + 1) != -1)

		{
			hrac.attack(hrac.x, hrac.y + 1, entity_list);
			break;
		}

		else if (mapa.check_wall_collision(hrac.x, hrac.y + 1) == 0)
			{
				break;
			}
		//out of bounds for down
		if (hrac.y + 1 < ROWS) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.y++;
		}
		break;
	case '1':

		if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y + 1) != -1)
		{
			hrac.attack(hrac.x - 1, hrac.y + 1, entity_list);
			break;
		}

		else if (mapa.check_wall_collision(hrac.x - 1, hrac.y + 1) == 0) 
			{
				break;
			}

		if ((hrac.x > 0) && (hrac.y + 1 < ROWS)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
			hrac.y++;
		}
		break;
	case '7':

		if (entity_list.find_entity_thru_coords(hrac.x - 1, hrac.y - 1) != -1)
		{
			hrac.attack(hrac.x - 1, hrac.y - 1, entity_list);
			break;
		}

		else if (mapa.check_wall_collision(hrac.x - 1, hrac.y - 1) == 0) 
			{
				break;
			}

		if ((hrac.x > 0) && (hrac.y > 0)) {
			hrac.prev_x = hrac.x;
			hrac.prev_y = hrac.y;
			hrac.x--;
			hrac.y--;
		}
		break;
	}
}