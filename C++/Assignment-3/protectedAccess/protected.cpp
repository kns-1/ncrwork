#include<iostream>
#include<conio.h>
using namespace std;

class Base
{
protected:
	int pr;
public:
	Base()
	{
		cout << "Base class" << endl;
		pr = 10;
	}
};

class Derived :protected Base
{
public:
	Derived()
	{
		cout << "Derived class" << endl;
		cout << pr;//accessible as it is a protected member of the base class
	}
};
void main()
{
	Base *ob;
	ob = new Base();
	//cout<<ob->pr; //not accessible as it is a protected member of the base class
	//ob = new Derived();// not possible as derived class is protectedly inheriting base class
	Derived ob1;
	//cout << ob1.pr;//not accessible as it is a protected member of the base class

	_getch();
}