#include<iostream>
#include<conio.h>
using namespace std;

class Base
{
private:
	int pr;
public:
	Base()
	{
		cout << "Base class" << endl;
		pr = 10;
	}
};

class Derived :private Base
{
public:
	Derived()
	{
		cout << "Derived class" << endl;
		//cout << pr;//not accessible as it is a private member of the base class
	/*	Base b;
		cout << b.pr;//not accessible as it is a private member of the base class
		*/
	}
};
void main()
{
	Base *ob;
	ob = new Base();
	//cout<<ob->pr; //not accessible as it is a private member of the base class
//	ob = new Derived();// not possible as derived class is privately inheriting base class
	Derived ob1;

	_getch();
}