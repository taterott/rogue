#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Input.hpp"


class MainLoop
{
public:
	Player hrac;
	WorldMap mapa;
	Input input;
	Entities entity;
	Text text_log;


	//is there actually any reason to use the static keyword
	//for methods? except safeguarding? doesn't really apply here?
	void render_screen();
	void handle_events();
	void init();

	void run();
};