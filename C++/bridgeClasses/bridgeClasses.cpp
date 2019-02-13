#include<conio.h>
#include<iostream>
using namespace std;

class Distance2;
class Distance1
{
	double m, cm;
public:
	Distance1(double m, double cm)
	{
		this->m = m;
		this->cm = cm;
	}
	friend void addNum();
	void displayResult()
	{
		cout << "Result is: " << m <<" feet, "<<cm<<" inches"<< endl;
	}
};
class Distance2
{
	double ft, inch;
public:
	Distance2(double ft, double inch)
	{
		this->ft = ft;
		this->inch = inch;
	}
	friend void addNum();
};
void addNum()
{
	Distance1 d1(2.34,7.323);
	Distance2 d2(3.342,1.234);
	d1.m = (d1.m * 3.28084) + d2.ft;
	d1.cm = (d1.cm * 0.393701) + d2.inch;
	d1.displayResult();
}
void main()
{
	addNum();
	_getch();
}