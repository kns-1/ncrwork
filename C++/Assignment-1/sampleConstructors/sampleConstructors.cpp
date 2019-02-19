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
		cout << "one arg constructor" << endl;
	}
	void callByValue(Employee e)
	{
		cout << "call by value" << endl;
	}
	void callByReference(Employee &e)
	{
		cout << "call by reference" << endl;
	}
	~Employee()
	{
		cout << "Destructor"<<endl;
	}
};

void main()
{
	Employee e1(10, 20);
	Employee e2(30);
	Employee e3,e4;
	e3.callByValue(e4); //destructor is invoked
	e3.callByReference(e4);
//	e1.~Employee(); //explicit destructor calling
	_getch();
}