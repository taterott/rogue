#pragma once

#include "Generic.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Text
{
public:
	
	int render_log();
	void append_to_log(std::string text);

	int max_render_len = ROWS * COLUMNS;


	//technically does not have to be this way - the chatlog can be under, over, to the side etc. i just thought it'd 
	//be best if we have it in teh same dimensinos next to the map for now, and see what happenss
	int text_log_lines = ROWS;
	int text_log_line_length = COLUMNS;

	std::vector<std::string> text_log;
};

class Dialogue
{
public:
	int line_index = 0;
	std::vector<std::string> dialogue_array;
	std::string dialogue_string;

	int load_dialogue_from_text(std::string& dialogue_location);

	void render_dialogue(Text& text_log);

	void convert_dialogue();

};

