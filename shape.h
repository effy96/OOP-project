using namespace std;
#ifndef _Shape_
#define _Shape_
#include<cstring>;
#include<iostream>
/*
enum type_Shape
{
	Circle_,
	Ellipse_,
	Rect_,
	Line_,
	None_
};*/

class Shape
{
public:
	Shape();
	Shape(const Shape&);
	virtual Shape& operator=(const Shape&);
	virtual ~Shape();
public:
	virtual char* set_fill(char*);
	virtual char* set_stroke(char*);
	virtual double set_width(double);
	virtual char* get_fill();
	virtual char* get_stroke();
	virtual double get_width();
	virtual void set_number(unsigned);;
	virtual unsigned get_number();
	
	//virtual	void set_type(unsigned);
public:
	virtual void get_data(char*) = 0;
	virtual void save(fstream&) = 0;
	virtual void print() = 0;
	virtual void translate(double,double)=0;
private:
	//type_Shape	type;
	char* fill;
	char * stroke;
	double stroke_width;
	unsigned shapes_number;
};

Shape::Shape()
{
	fill = nullptr;
	stroke = nullptr;
	stroke_width = 0;
	shapes_number = 0;
	//type = None_;
}

inline Shape::Shape(const Shape &a)
{
	this->operator=(a);
}

inline Shape & Shape::operator=(const Shape &a)
{
	if (this != &a)
	{
		set_fill(a.fill);
		set_stroke(a.stroke);
		stroke = a.stroke;
		shapes_number = a.shapes_number;
		//type = a.type;
	}
	return *this;
}
Shape::~Shape()
{
	fill = nullptr;
	stroke = nullptr; // zashto ne rabvoti delete
	stroke_width = 0;
	shapes_number = 0;
	//type = None_;
}

inline void Shape::print()// print shape
{
	cout << fill << " " << stroke << " " << stroke_width << endl;
}
 

inline char* Shape::set_fill(char*a)
{
	if (a == nullptr || a == NULL) return nullptr;
	unsigned len = strlen(a);
	char* temp = new(nothrow) char[len + 1];
	if (!temp) return nullptr;
	strcpy_s(temp, len + 1, a);
	fill = temp;
	return fill;
}

inline char* Shape::set_stroke(char *a)
{
	if (a == nullptr || a == NULL) return nullptr;
	unsigned len = strlen(a);
	char* temp = new(nothrow) char[len + 1];
	if (!temp) return nullptr;
	strcpy_s(temp, len + 1, a);
	stroke = temp;
	return stroke;
}

inline double Shape::set_width(double a)
{
	stroke_width = a;
	return stroke_width;
}

inline char* Shape::get_fill()
{
	return fill;
}

inline char* Shape::get_stroke()
{
	return stroke;
}

inline double Shape::get_width()
{
	return stroke_width;
}

inline void Shape::set_number(unsigned a)
{
	shapes_number = a;
}

inline unsigned Shape::get_number()
{
	return shapes_number;
}
/*
inline void Shape::set_type(unsigned number)
{
	switch (number)
	{
	case 0:
		type = Circle_;
		break;
	case 1:
		type = Ellipse_;
		break;
	case 2:
		type = Rect_;
		break;
	case 3:
		type = Line_;
		break;
	default:
		type = None_;
		break;
	}
}*/


#endif // !_Shape_
