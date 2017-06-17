#ifndef _Line_
#define _Line_
#include<iostream>
#include"shape.h"
#include"functions.h"
using namespace std;
class Line : public Shape
{
public:
	Line();
	Line(const Line&);
	Line& operator=(const Line&);
	~Line(); 
	void set_x1(double);
	void set_x2(double);
	void set_y1(double);
	void set_y2(double);
	virtual void get_data(char*);
	virtual void save(fstream&);
	virtual void print();
	virtual void translate(double, double);

private:
	double x1, x2, y1, y2;
};

Line::Line()
	:Shape()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

inline Line::Line(const Line &a)
	:Shape(a)
{
	*this = a;
}

inline Line & Line::operator=(const Line &a)
{
	if (this != &a)
	{
		x1 = a.x1;
		y1 = a.y1;
		x2 = a.x2;
		y2 = a.y2;
		
	}
	return *this;
}


Line::~Line() 
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

inline void Line::print()
{
	cout << get_number() << " line " << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
	if (this->get_fill() != NULL)cout << get_fill() << " ";
	if (this->get_stroke() != NULL)cout << get_stroke() << " ";
	if (this->get_width() != NULL)cout << get_width() << " "; 
	cout << endl;
}


inline void Line::set_x1(double a)
{
	x1 = a;
}
inline void Line::set_x2(double a)
{
	x2 = a;
}
inline void Line::set_y1(double a)
{
	y1 = a;
}
inline void Line::set_y2(double a)
{
	y2 = a;
}
inline void Line::get_data(char * row)
{
	char*b = strtok(row, "< >"); 
	while (b != NULL)
	{
		b = strtok(NULL, "< >/");
		if (b != NULL&&strstr(b, "x1=\""))
		{
			set_x1((get_number_from_str(b, "x1=\"")));
		}
		if (b != NULL&&strstr(b, "x2=\""))
		{
			set_x2((get_number_from_str(b, "x2=\"")));
		}
		if (b != NULL&&strstr(b, "y1=\""))
		{
			set_y1((get_number_from_str(b, "y1=\"")));
		}
		if (b != NULL&&strstr(b, "y2=\""))
		{
			set_y2((get_number_from_str(b, "y2=\"")));
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

inline void Line::save(fstream& file)
{
	file << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2
		<< "\" fill=\"" << this->get_fill() << "\" stroke =\"" << get_stroke()
		<< "\" stroke-width=\"" << get_width() << "\" / >" << endl;
}
inline void Line::translate(double a, double b)
{
	set_x1(x1 + a);
	set_y1(y1 + b);
	set_x2(x2 + a);
	set_y2(y2 + b);
	 
}

#endif // !_Line_

