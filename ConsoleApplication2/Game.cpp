#include "Game.hpp"

void MainLoop::render_screen()
{
	std::cout.flush();
	system("CLS");
	mapa.print_map();
	text_log.render_log();
}

void MainLoop::handle_events()
{
	hrac.move_player();
	entity.move_all_entities();
	input.player_movement(mapa, hrac, entity, text_log);

}

//init has to have npc spawning and entity administrating features
//once i fix the constructor for npc
void MainLoop::init()
{
	//sets our the_handle var to standard output in console
	//this is for our SetConsoleCursorPosition windows api usage
	if (the_handle == nullptr)
	{
		the_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	mapa.load_map_from_txt("map.txt");
}

void MainLoop::run()
{
	entity.create_npc('E', "Delta", 3, 3, 2, true);
	entity.create_npc('F', "Filip", 20, 20, 420, false);

	init();

	while (true)
	{
		render_screen();
		handle_events();
		if (input.recent_input == 'q')
		{
			break;
		}
	}

	system("CLS");
	std::cout.flush();
	std::cout << "Game was shut down. Thank you for playing!" << std::endl;

	entity.dealloc_entities();
}
