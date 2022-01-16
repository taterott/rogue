#pragma once

#include "Windows.h"
#include <fstream>
#include <iostream>
#include <string>

#define ROWS 25
#define COLUMNS 25

int get_string_from_file(std::string& file_location, std::string& target);

extern HANDLE the_handle;
