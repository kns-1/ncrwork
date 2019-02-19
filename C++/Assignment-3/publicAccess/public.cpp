#include<iostream>
#include<conio.h>
using namespace std;

class Base
{
public:
	int pr;
	Base()
	{
		cout << "Base class" << endl;
		pr = 10;
	}
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived class" << endl;
		cout << pr<<endl;//accessible as it is a public member of the base class
	}
};
void main()
{
	Base *ob;
	ob = new Base();
	cout<<ob->pr<<endl; //accessible as it is a public member of the base class
	ob = new Derived();// possible as derived class is publicly inheriting base class
	cout << ob->pr<<endl;// accessible as it is a public member of the base class

	_getch();
}