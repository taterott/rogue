#include "Generic.hpp"

//reads from a text file at specified location and 
//parses it into a biiig string
int get_string_from_file(std::string& file_location, std::string& target)
{
	std::fstream file;
	file.open(file_location);

	if (!file)
	{
		std::cout << "Couldn't find file at that location" << std::endl;
		file.close();
		return 0;
	}
	else
	{
		std::getline(file, target, '@');
		file.close();
		return 1;
	}
}