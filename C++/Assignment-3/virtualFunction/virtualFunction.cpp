#include<iostream>
#include<conio.h>
using namespace std;

class Shape
{
protected:
	int a, b;
public:
	void read()
	{
		cout << "enter a and b: ";
		cin >> a >> b;
	}
	virtual void display_area()
	{
		cout << "Base class: "<<a<<" "<<b<<endl;
	}
};
class Triangle : public Shape
{
public:
	void display_area()
	{
		cout << "Triangle Area = " << (a * b) / 2 << endl;
	}
};
class Square : public Shape
{
public:
	void display_area()
	{
		cout << "Square Area = " << (a * a) << endl;
	}
};
class Rectangle : public Shape
{
public:
	void display_area()
	{
		cout << "Rectangle Area = " << (a * b) << endl;
	}
};

void main()
{
	Shape *s;
	s = new Shape();
	s->read();
	s->display_area();
	s = new Triangle();
	s->read(); s->display_area();
	s = new Square();
	s->read(); s->display_area();
	s = new Rectangle();
	s->read(); s->display_area();
	_getch();
}