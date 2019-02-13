#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Point
{
	double x, y, dist;
public:
	Point()
	{
		x = y = 0;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	friend void calDistance(Point &p1, Point &p2);
	void display()
	{
		cout << "Distance= " << dist << endl;
	}
};
void calDistance(Point &p1, Point &p2)
{
	Point p;
	p.dist = pow((p2.y - p1.y), 2) + pow((p2.x - p1.x), 2);
	p.dist = sqrt(p.dist);
	p.display();
}
void main()
{
	Point p1(51.234, 21.245);
	Point p2(14.346, 67.321);
	calDistance(p1, p2);
	_getch();
}