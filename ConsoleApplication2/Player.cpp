#include "Player.hpp"
void Player::attack(int x, int y, Entities& entity_list, Text& text_log)
{
	int npc_index = entity_list.find_entity_thru_coords(x, y);
	if (npc_index != -1)
	{
		if (entity_list.npcs[npc_index]->enemy == true) 
		{
			entity_list.npcs[npc_index]->current_health--;
			Beep(523, 100);
			Beep(123, 100);
			text_log.append_to_log(entity_list.npcs[npc_index]->name + " took " + std::to_string(damage) + " points of damage.");

			if (entity_list.npcs[npc_index]->current_health <= 0)
			{
				Beep(323, 100);
				text_log.append_to_log(entity_list.npcs[npc_index]->name + " died.");
				entity_list.npcs.erase(entity_list.npcs.begin() + npc_index);
			}
		}

		else if (entity_list.npcs[npc_index]->enemy == false)
		{
			Beep(130.81, 100);
			Beep(196.00, 100);
			entity_list.npcs[npc_index]->npc_dialogue.render_dialogue(text_log);
		}
	}
}

void Player::move_player() {
	go_to_xy(x, y);
	std::cout << '@';
}