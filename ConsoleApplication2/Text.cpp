#pragma once
#include "text.hpp"


void Text::append_to_log(std::string text)
{
	if (text_log.size() >= 25)
	{
		text_log.erase(text_log.begin());
	}
	text_log.push_back(text);

}

int Text::render_log()
{
	if (text_log.size() == 0)
	{
		return 0;
	}

	if (the_handle == nullptr)
	{
		the_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	COORD cord;
	cord.X = 30;
	cord.Y = 0;

	//SetConsoleCursorPosition(the_handle, cord);

	for (int i = 0; i < text_log.size(); i++)
	{
		SetConsoleCursorPosition(the_handle, cord);
		std::cout << text_log[i] << std::endl;
		cord.Y++;
	}

	return 1;
}

/* s s s s*/