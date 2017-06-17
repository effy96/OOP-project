#ifndef _Ellipse_
#define _Ellipse_
#include<iostream>
#include"shape.h"
using namespace std;
class Ellipse : public Shape
{
public:
	Ellipse();
	Ellipse(const Ellipse&);
	Ellipse& operator=(const Ellipse&);
	~Ellipse();
	void set_cx(double);
	void set_cy(double);
	void set_rx(double);
	void set_ry(double);
	virtual void print();
	virtual void get_data(char*);
	virtual void save(fstream&);
	virtual void translate(double, double);

private:
	double cx, cy,
		rx,ry;
};

Ellipse::Ellipse()
{
	cx = 0;
	cy = 0;
	rx = 0;
	ry = 0;
}

inline Ellipse::Ellipse(const Ellipse &a)
	:Shape(a)
{
	*this = a;
}

inline Ellipse & Ellipse::operator=(const Ellipse &a)
{
	if (this != &a)
	{
		cx = a.cx;
		cy = a.cy;
		rx = a.rx;
		ry= a.ry;
	}
	return *this;
}


Ellipse::~Ellipse()
{
	cx = 0;
	cy = 0;
	rx = 0;
	ry = 0;
}

inline void Ellipse::set_cx(double a)
{
	cx = a;
}

inline void Ellipse::set_cy(double a)
{
	cy = a;
}

inline void Ellipse::set_rx(double a)
{
	rx = a;
}

inline void Ellipse::set_ry(double a)
{
	ry = a;
}

inline void Ellipse::print()
{
	cout << get_number() << " ellipse " << cx << " " << cy << " " << rx << " " << ry << " ";
	if (this->get_fill() != NULL)cout << get_fill() << " ";
	if (this->get_stroke() != NULL)cout << get_stroke() << " ";
	if (this->get_width() != NULL)cout << get_width() << " "; 
	cout << endl;
}

inline void Ellipse::get_data(char* row)
{

	char*b = strtok(row, "< >");
	while (b != NULL)
	{
		b = strtok(NULL, "< >/");
		if (b != NULL&&strstr(b, "cx=\""))
		{
			set_cx((get_number_from_str(b, "cx=\"")));
		}
		if (b != NULL&&strstr(b, "rx=\""))
		{
			set_rx((get_number_from_str(b, "rx=\"")));
		}
		if (b != NULL&&strstr(b, "ry=\""))
		{
			set_ry((get_number_from_str(b, "ry=\"")));
		}

		if (b != NULL&&strstr(b, "cy=\""))
		{
			set_cy((get_number_from_str(b, "cy=\"")));
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



inline void Ellipse::save(fstream& file)
{
	file << "<ellipse cx=\"" << cx << "\" cy=\"" << cy << "\" rx=\"" << rx<<"\" ry=\""<<ry
		<< "\" fill=\"" << this->get_fill() << "\" stroke =\"" << get_stroke()
		<< "\" stroke-width=\"" << get_width() << "\" / >" << endl;
}

inline void Ellipse::translate(double x2, double y2)
{
	set_cx(cx + x2);
	set_cy(cy + y2);
}


#endif // !_Ellipse_

