#include "Generic.hpp"

//should this be extern? hyuck
void get_string_from_file(std::string file_location, std::string& target)
{
	std::fstream file;
	file.open(file_location);

	if (!file)
	{
		std::cout << "Couldn't find file at that location" << std::endl;
	}
	else
	{
		std::getline(file, target, '@');
	}

	file.close();
}