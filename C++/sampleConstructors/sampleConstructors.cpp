#include<iostream>
#include<conio.h>
using namespace std;

class Employee
{
	int id, ph;
public:
	Employee()
	{
		id = ph = 0;
		cout << "default constructor" << endl;
	}
	Employee(int i, int p)
	{
		id = i;
		ph = p;
		cout << "two arg constructor" << endl;
	}
	Employee(int i)
	{
		id = ph = i;
		cout << "one ard constructor" << endl;
	}
	~Employee()
	{
		cout << "Destructor";
	}
};

void main()
{
	Employee e1(10, 20);
	Employee e2(30);
	Employee e3;
	e1.~Employee();
	_getch();
}