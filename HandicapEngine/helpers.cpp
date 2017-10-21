#include "Helpers.h"

std::string read_file(const char * file_path)
{
	FILE *file = fopen(file_path, "rt");
	fseek(file, 0, SEEK_END); 
	unsigned long lenght = ftell(file);
	char *data = new char[lenght+1];
	memset(data, 0, lenght + 1);
	fseek(file, 0, SEEK_SET);
	fread(data, 1, lenght, file);
	//fread_s(data, 1, lenght, 1, file);
	fclose(file); 

	std::string string_data(data);
	delete[] data;

	return string_data;
}
