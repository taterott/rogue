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

int Dialogue::load_dialogue_from_text(std::string& dialogue_location)
{

	if (get_string_from_file(dialogue_location, dialogue_string) == 1)
	{
		convert_dialogue();
		return 1;
	}
	else
	{
		return 0;
	}
}

void Dialogue::convert_dialogue()
{
	std::stringstream s(dialogue_string);

	std::string str_to_push;

	while (std::getline(s, str_to_push, '\n'))
	{
		dialogue_array.push_back(str_to_push);
	}


}

void Dialogue::render_dialogue(Text& text_log)
{
	if (dialogue_array.size() > 0)
	{
		text_log.append_to_log(dialogue_array[line_index]);
		if (line_index < dialogue_array.size() - 1)
		{
			line_index++;
		}
	}
}

/* s s s s*/