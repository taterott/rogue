#include "Player.hpp"
void Player::attack(int x, int y, Entities entity_list)
{
	int npc_index = entity_list.find_entity_thru_coords(x, y);
	if (npc_index != -1)
	{
		entity_list.npcs[npc_index]->current_health--;
		if (entity_list.npcs[npc_index]->current_health <= 0)
		{
			delete entity_list.npcs[npc_index];
		}
	}
}

void Player::go_to_xy(int x, int y)
{
	if (the_handle == nullptr)
	{
		the_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = x;
	cord.Y = y;

	SetConsoleCursorPosition(the_handle, cord);
}


void Player::move_player() {
	go_to_xy(x, y);
	std::cout << '@';
}