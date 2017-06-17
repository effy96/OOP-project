#ifndef _rect_
#define _rect_
#include"shape.h"
#include"functions.h"
#include<iostream>
using namespace std;
class Rect : public Shape
{
public:
	Rect();
	Rect(const Rect&);
	Rect& operator=(const Rect&);
	~Rect();
	void set_x(double);
	void set_y(double);
	void set_width_r(double);
	void set_height_r(double);
	virtual void print();
	virtual void get_data(char*);
	virtual void save(fstream&);
	virtual void translate(double, double);
private:
	 double x, y, width,height;
};	

Rect::Rect()
	:Shape()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

inline Rect::Rect(const Rect &a)
	:Shape(a)
{
	*this = a;
}

inline Rect & Rect::operator=(const Rect &a) 
{ 
	if (this != &a)
	{
		x = a.x;
		y = a.y;
		width = a.width;
		height = a.height;
	}
	return *this;
}


Rect::~Rect()
{
	x = 0;
	y = 0;
	width = 0;
	height = 0;
}

inline void Rect::set_x(double a)
{
	x = a;
}
inline void Rect::set_y(double a)
{
	y = a;
}
inline void Rect::set_width_r(double a)
{
	width = a;
}
inline void Rect::set_height_r(double a)
{
	height = a;
}
inline void Rect::print()
{
	cout << get_number() << " rect " << x << " " << y << " " << width << " " << height << " " ;
	if (this->get_fill() != NULL)cout << get_fill() << " ";
	if (this->get_stroke() != NULL)cout << get_stroke() << " ";
	if (this->get_width() != NULL)cout << get_width() << " ";
	cout << endl;
}
inline void Rect::get_data(char* row)
{
	char*b = strtok(row, "< >"); 
	while (b != NULL)
	{
		b = strtok(NULL, "< >/");

		if (b != NULL&&strstr(b, "x=\""))
		{
			set_x((get_number_from_str(b, "x=\"")));
		}

		if (b != NULL&&strstr(b, "y=\""))
		{
			set_y((get_number_from_str(b, "y=\"")));
		}
		if (b != NULL&&strstr(b, "width=\"") && !(strstr(b, "stroke-width=\"")))
		{
			set_width_r((get_number_from_str(b, "width=\"")));
		}
		if (b != NULL&&strstr(b, "height=\""))
		{
			set_height_r((get_number_from_str(b, "height=\"")));
		}

		if (b != NULL&&strstr(b, "stroke-width=\""))
		{
			set_width((get_number_from_str(b, "stroke-width=\"")));
		}
		if (b != NULL && strstr(b, "fill=\""))
		{
			set_fill(get_color_from_str(b, "fill=\""));
		}
		if (b != NULL && strstr(b, "stroke=\""))
		{
			set_stroke(get_color_from_str(b, "stroke=\""));
		}

	}//-| while; 
	delete b; 

}

inline void Rect::save(fstream& file)
{
	file << "<rect x=\"" << x << "\" y=\"" << y << "\" height=\"" << height << "\" width=\"" << width
		<< "\" fill=\"" << this->get_fill() << "\" stroke =\"" << get_stroke()
		<< "\" stroke-width=\"" << get_width() << "\" / >" << endl;
}
inline void Rect::translate(double a , double b)
{
	set_x(x + a);
	set_y(y + b);
}
#endif // !_rect_
