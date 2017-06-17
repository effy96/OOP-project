#include<iostream>
#include<cstring>
#include<fstream>
#include"filess.h"
using namespace std;
int main()
{
	/*

	Относно функцията create се подават стойности : cx=".." cy="..." r=".."
	пример: > create circle cx="43" cy="4" r="455" fill="green" stroke="red" stroke-width="2"

	*/
	char command[200];
	bool valid_command = false;

	Shape** shapes = nullptr;
	char* directory = nullptr;


	do
	{
		cin.getline(command, 200);
		valid_command = false;
		if (strstr(command, "> open") && command[0] == '>')
		{
			directory = return_directory_from_command(command);
			Shape** shapes = open_file(directory);
			valid_command = true;
			do
			{
				cin.getline(command, 200);
				valid_command = false;
				if (!strcmp(command, "> print"))
				{
					print_shapes(shapes);
					valid_command = true;
				}
				if (strstr(command, "> create") && command[0] == '>')
				{
					shapes = add_fig(shapes, command);
					valid_command = true;
				}
				if (strstr(command, "> erase ") && command[0] == '>')
				{
					char* number = strtok(command, "> erase");
					unsigned position = atof(number);
					if (position > NUMBER_OF_SHAPES)
					{
						cout << "There is no figure number " << position << "!" << endl;
					}
					else
					{
						shapes = del_fig(shapes, position);
					}
					valid_command = true;
				}
				if (strstr(command, "> translate"))
				{
					shapes = translate_all_shapes(shapes, command);
					valid_command = true;
				}
				if (strstr(command, "> save") && (!strstr(command, "> saveas")) && command[0] == '>')
				{

					save_file(shapes, directory);
					valid_command = true;
				}

				if (strstr(command, "> saveas") && command[0] == '>')
				{
					directory = get_direct_save_as(command);
					cout << "save as file" << endl;
					save_file(shapes, directory);
					valid_command = true;
				}
				if (strstr(command, "> close") && command[0] == '>')
				{
					delete[] shapes;
					cout << "Closed file" << get_name_of_file(directory) << endl;
				}


			} while (valid_command);
			valid_command = true;
		}

	} while (valid_command);
	system("pause");
	return 0;
}