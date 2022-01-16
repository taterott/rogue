#include "Game.hpp"

//Flushes output, clears console, prints our map and renders our text log
void MainLoop::render_screen()
{
	std::cout.flush();
	system("CLS");
	mapa.print_map();
	text_log.render_log();
}

//Handles our events, that is -> moves player according to previous movement,
//handles entity movement and takes input from player for next move
void MainLoop::handle_events()
{
	hrac.move_player();
	entity.move_all_entities();
	input.player_movement(mapa, hrac, entity, text_log);

}

//Here we put stuff we wanna load up - the map and its NPCs
void MainLoop::init()
{
	//sets our the_handle var to standard output in console
	//this is for our SetConsoleCursorPosition windows api usage
	if (the_handle == nullptr)
	{
		the_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	mapa.load_map_from_txt("map.txt");
	entity.create_npc('f', "filip", 20, 20, 420, false);
	entity.create_npc('c', "katusa", 21, 21, 69, false);
}
//our mainloop run - self explanatory
void MainLoop::run()
{
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
