#include<iostream>
#include<conio.h>
using namespace std;
class Polar
{
	static int angle, radius;
	static int n;
public:
	Polar()
	{
		n++;
	}
   static void fun()
	{
	   angle++;
	   radius++;
		cout << "Number of objects= "<<n<< endl<< "Angle= " << angle<<"\nRadius= "<<radius << endl;
	}
  
	~Polar()
	{
		cout << "Destructor" << endl;
	}
};
int Polar::angle = 50; //mandatory
int Polar::radius = 20; //mandatory
int Polar::n = 0;
void main()
{
	Polar p1;
	Polar p2;
	p1.fun();
	p1.fun();
	p2.fun();
	_getch();
}
