#ifndef _FILES_
#define _FILES_
#include<iostream>
using namespace std;
#include<fstream>
#include<cstring> 
#include"line.h"
#include"ellipse.h" 
#include"rect.h"
#include"shape.h"
#include"circle.h"
#include"functions.h"

unsigned NUMBER_OF_SHAPES = 0;
Shape* return_figure(char* row)
{
	Shape* a = nullptr;

	if (strstr(row, "<circle") && row[0] == '<')
	{
		a = new Circle;
		a->get_data(row);
		NUMBER_OF_SHAPES++;
		a->set_number(NUMBER_OF_SHAPES);
		return a;
	}
	if (strstr(row, "<ellipse") && row[0] == '<')
	{
		a = new Ellipse;
		a->get_data(row);
		NUMBER_OF_SHAPES++;
		a->set_number(NUMBER_OF_SHAPES);
		return a;
	}
	if (strstr(row, "<line") && row[0] == '<')
	{
		a = new Line;
		a->get_data(row);
		NUMBER_OF_SHAPES++;
		a->set_number(NUMBER_OF_SHAPES);
		return a;
	}
	if (strstr(row, "<rect") && row[0] == '<')
	{
		a = new Rect;
		a->get_data(row);
		NUMBER_OF_SHAPES++;
		a->set_number(NUMBER_OF_SHAPES);
		return a;
	}
	return a;
}

Shape** open_file(char name_of_file[193])
{
	fstream f(name_of_file, ios::in | ios::out | ios::app); //remove app
	Shape** shapes = nullptr;
	if (!f.is_open()) // ako failut ne moje da se otvori
	{
		cout << "cannot open file" << endl;
		return shapes;
	}
	if (f.eof())// ako e prazen suzdavame validen
	{
		f << "<svg xmlns = " << "http://www.w3.org/2000/svg" << " // >" << endl;
		cout << "Succesfully opened " << get_name_of_file(name_of_file);
		return shapes;
	}
	else
	{
		streampos beg, end;				//размер на файлът
		beg = f.tellg();
		unsigned size_of_file = 0;
		f.seekg(0, ios::end);
		end = f.tellg();
		size_of_file = (int)(end - beg);
		f.seekg(0, ios::beg);

		unsigned size = 0;
		do
		{
			char* info = new(nothrow) char[size_of_file + 1]; //proverka za zadelena pamet
			f.getline(info, size_of_file, '\n'); //взимаме всеки ред
			unsigned len = strlen(info);
			char* row = new (nothrow) char[len + 1];
			strncpy(row, info, (len + 1));
			row[len] = '\0';
			Shape* a = nullptr;
			a = return_figure(row);
			if (a != nullptr)
			{
				if (shapes == nullptr&&size == 0)
				{
					size++;
					shapes = new Shape*[1];
					shapes[0] = a;
				}
				else
				{
					size++;
					Shape** buff = new Shape*[size];
					for (int i = 0;i < size - 1;i++)
					{
						buff[i] = shapes[i];
					}
					buff[size - 1] = a;
					shapes = buff;
				}
			}

			delete[] row;
			delete[] info;
		} while (!f.eof());
	}
	f.close();

	cout << "Succesfully opened " << get_name_of_file(name_of_file) << endl;

	return shapes;
};
void save_file(Shape** shapes, char* directory)
{
	fstream file(directory, ios::in | ios::out | ios::trunc);

	file << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl
		<< "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd" << "\">" << endl
		<< "<svg>" << endl;

	for (int i = 0;i < NUMBER_OF_SHAPES;i++)
	{
		shapes[i]->save(file);
	}
	file << endl;
	file << "<svg/>" << endl;
	cout << "Successfully saved the changes to " << get_name_of_file(directory) << endl;
	file.close();
}
void print_shapes(Shape** shapes)
{
	//cout << "SHAPESSSS------" << endl;
	if (shapes != nullptr)
	{
		for (int i = 0;i < NUMBER_OF_SHAPES;i++)
		{
			(shapes[i])->print();
		}
	}
	else cout << "There's no shapes" << endl;
	//cout << "==============" << endl;
}
Shape** add_fig(Shape** shapes, char* row)
{

	Shape** buff = new (nothrow) Shape*[NUMBER_OF_SHAPES];

	for (int i = 0;i < NUMBER_OF_SHAPES;i++)
		buff[i] = shapes[i];
	delete[] shapes;
	char* info = new (nothrow) char[strlen(row) - 9 + 1];

	for (int i = 9;i < strlen(row);i++)
	{
		if (row[i] == '\0')
		{
			info[i - 9] = '\0';
			break;
		}
		info[i - 9] = row[i];
	}
	if (strstr(info, "circle"))
	{
		buff[NUMBER_OF_SHAPES] = new Circle;
		buff[NUMBER_OF_SHAPES]->get_data(info);
		NUMBER_OF_SHAPES++;
		buff[NUMBER_OF_SHAPES - 1]->set_number(NUMBER_OF_SHAPES);
		cout << "Successfully created circle (" << NUMBER_OF_SHAPES << ")" << endl;
		return buff;
	}
	if (strstr(info, "ellipse"))
	{
		buff[NUMBER_OF_SHAPES] = new Ellipse;
		buff[NUMBER_OF_SHAPES]->get_data(info);
		NUMBER_OF_SHAPES++;
		buff[NUMBER_OF_SHAPES - 1]->set_number(NUMBER_OF_SHAPES);
		cout << "Successfully created ellipse (" << NUMBER_OF_SHAPES << ")" << endl;
		return buff;
	}
	if (strstr(row, "line"))
	{
		buff[NUMBER_OF_SHAPES] = new Line;
		buff[NUMBER_OF_SHAPES]->get_data(info);
		NUMBER_OF_SHAPES++;
		buff[NUMBER_OF_SHAPES - 1]->set_number(NUMBER_OF_SHAPES);
		cout << "Successfully created line (" << NUMBER_OF_SHAPES << ")" << endl;
		return buff;
	}
	if (strstr(row, "rect"))
	{
		buff[NUMBER_OF_SHAPES] = new Rect;
		buff[NUMBER_OF_SHAPES]->get_data(info);
		NUMBER_OF_SHAPES++;
		buff[NUMBER_OF_SHAPES - 1]->set_number(NUMBER_OF_SHAPES);
		cout << "Successfully created rectangle (" << NUMBER_OF_SHAPES << ")" << endl;
		return buff;
	}
}
Shape** del_fig(Shape** shapes, unsigned pos)
{
	Shape** buff = new(nothrow) Shape*[NUMBER_OF_SHAPES - 1];
	for (int i = 0;i < NUMBER_OF_SHAPES - 1;i++)
	{
		if (shapes[i]->get_number() == pos)
		{
			unsigned re = shapes[i]->get_number();
			i++;
			for (int j = i;i < NUMBER_OF_SHAPES;j++, i++)
			{
				buff[j - 1] = shapes[i];
				buff[j - 1]->set_number(j);
			}
		}
		buff[i] = shapes[i];
	}
	NUMBER_OF_SHAPES--;
	cout << "Erased (" << pos << ")" << endl;
	delete[] shapes;
	return buff;
}
Shape** translate_all_shapes(Shape** shapes, char* row)
{
	char* info = new char[strlen(row) - 12 + 1];
	for (int i = 0;i < strlen(row) - 10;i++)
	{
		if (row[i + 12] == '\0')
		{
			info[i] = '\0';
			break;
		}
		info[i] = row[i + 12];
	}
	char* values = strtok(info, " ");
	double x, y;
	int number = -1;
	while (values != NULL)
	{

		if (strstr(values, "horizontal="))
		{
			x = get_values_for_translate(values, "horizontal=");
		}
		else
			if (strstr(values, "vertical="))
			{
				y = get_values_for_translate(values, "vertical=");
			}
			else
			{
				number = atof(values);
			}
		values = strtok(NULL, " ");
	}
	if (number == -1)
	{
		for (int i = 0;i < NUMBER_OF_SHAPES;i++)
		{
			shapes[i]->translate(x, y);
		}
		cout << "Translated all figures" << endl;
	}
	else
	{
		number--;
		shapes[number]->translate(x, y);
	}
	return shapes;
}

#endif // !_FILES_

