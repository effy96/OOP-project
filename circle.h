#ifndef _Circle_
#define _Circle_
#include<iostream> 
#include"functions.h"
using namespace std; 
class Circle: public Shape
{
public:
	Circle();
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	~Circle();
public:
	void set_r(const double);
	void set_y(const double);
	void set_x(const double);
	virtual void print();
	virtual void get_data(char*); 
	virtual void save(fstream&);
	virtual void translate(double,double);
private:
	double cx, cy,
		r;
};

Circle::Circle():Shape()
{
	cx = 0;
	cy = 0;
	r = 0;
}

inline Circle::Circle(const Circle &a)
	:Shape(a)
{
	*this = a;
}

inline Circle & Circle::operator=(const Circle &a)
{
	if (this != &a)
	{
		cx = a.cx;
		cy = a.cy;
		r = a.r;
	}
	return *this;
} 
Circle::~Circle()
{
	cx = 0;
	cy = 0;
	r = 0;
} 
inline void Circle::set_r(const double a)
{
	r = a;
}
inline void Circle::set_y(const double a)
{
	cy = a;
}
inline void Circle::set_x(const double a)
{
	cx = a;
}
inline void Circle::print()
{
	cout << get_number()<< " circle " << r << " " << cx << " " << cy<<" ";
	if (this->get_fill() != NULL)cout << get_fill() << " ";
	if (this->get_stroke() != NULL)cout << get_stroke() << " ";
	if (this->get_width() != NULL)cout << get_width() << " ";
	//<< this->get_stroke() << this->get_width();
	cout << endl;
}
inline void Circle::get_data( char* row)
{
	char*b = strtok(row, "< >/");
	while (b != NULL)
	{
		b = strtok(NULL, "< >/");
		if (b != NULL&&strstr(b, "r=\""))
		{
			set_r((get_number_from_str(b, "r=\"")));
		}
		if (b != NULL&&strstr(b, "cx=\""))
		{
			set_x((get_number_from_str(b, "cx=\"")));
		}
		if (b != NULL&&strstr(b, "cy=\""))
		{
			set_y((get_number_from_str(b, "cy=\"")));
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
inline void Circle::save(fstream& file)
{
 	file << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r 
		<< "\" fill=\"" << this->get_fill() << "\" stroke=\"" << get_stroke()
		<< "\" stroke-width=\"" << get_width() << "\" / >" << endl;
 
}

inline void Circle::translate(double x2, double y2)
{
	set_x(cx + x2);
	set_y(cy + y2);
}

#endif // !_Circle_

