#include<iostream>
#ifndef _FUNCTIONS_
#define _FUNCTIONS_
using namespace std;
char* get_name_of_file(char* name_of_file)
{
	char* name = new char[strlen(name_of_file) + 1];
	int begin = 0;
	for (int i = 200;i > 0;i--)
		if (name_of_file[i] == '\\') begin = i + 1;
	for (int i = begin;i < 193;i++)
	{
		if (name_of_file[i] == '\0') break;
		name[i - begin] = name_of_file[i];
	}
	name[strlen(name_of_file) - begin] = '\0';
	return name;
}
char* return_directory_from_command(char* command)
{
	char* directory=new(nothrow) char[193];
	for (int i = 7;i < 200;i++)
	{
		if (command[i] == '\0')
		{
			directory[i - 7] = '\0';
			break;
		}
		directory[i - 7] = command[i];
	} 
	return directory;
}
char* get_direct_save_as(char* command)
{
	char* directory = new(nothrow) char[191];
	for (int i = 9;i < 200;i++)
	{
		if (command[i] == '\0')
		{
			directory[i - 9] = '\0';
			break;
		}
		directory[i - 9] = command[i];
	}
	return directory;
}
double get_number_from_str(char * str, char* srch)
{
	if (str != NULL && strstr(str, srch))
	{
		char* number = new char[strlen(str) + 1 - (strlen(srch) + 1)];
		for (int i = 0;i < strlen(str) + 1 - (strlen(srch) + 1);i++)
		{
			if (str[i + strlen(srch)] == '\"') { number[i] = '\0';break; }
			number[i] = str[i + strlen(srch)];
		}
		double x = atof(number);
		delete number;
		return x;
	}
	return 0;
}
char* get_color_from_str(char*str, char* srch)
{
	if (str != NULL && strstr(str, srch))
	{
		char* color = new char[strlen(str) + 1 - (strlen(srch) + 1)];
		for (int i = 0;i < strlen(str) + 1 - (strlen(srch) + 1);i++)
		{
			if (str[i + strlen(srch)] == '\"') { color[i] = '\0';break; }
			color[i] = str[i + strlen(srch)];
		}
		return color;
	}
} 
double get_values_for_translate(char* str, char* srch)
{

	char* number = new char[strlen(str) + 1 - (strlen(srch))];
	for (int i = 0;i < strlen(str) + 1 - (strlen(srch) );i++)
	{
		if (str[i + strlen(srch)] == '\0') { number[i] = '\0';break; }
		number[i] = str[i + strlen(srch)];
	}
	double x = atof(number);
	delete number;
	return x;

}
#endif // !_FUNCTIONS_