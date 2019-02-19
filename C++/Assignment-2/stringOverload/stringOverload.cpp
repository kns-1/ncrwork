#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class StringOverload
{
	string *mystring=NULL;
public:
	StringOverload()
	{
		cout << "default constructor" << endl;
	}
	StringOverload(int size)
	{
		mystring = new string[size];
		cout << "one arg constructor" << endl;
	}
	
	StringOverload(StringOverload* &ob, int size)
	{
		mystring = ob->mystring;
		cout << "copy constructor" << endl;
	}

	friend istream& operator>>(istream& cin, StringOverload* &s);
	friend ostream& operator<<(ostream& cout, StringOverload* s);
	StringOverload* operator+(StringOverload &s);


	~StringOverload()
	{
		delete mystring;
		cout << "Destructor" << endl;
	}
};


istream& operator>>(istream& cin, StringOverload* &s)
{
	cout << "enter string: ";
	getline(cin, s->mystring);
	return cin;
}

ostream& operator<<(ostream& cout, StringOverload* s)
{
	cout << "String is: " << s->mystring << endl;
	return cout;
}

StringOverload* StringOverload::operator+(StringOverload &s)
{
	StringOverload *temp=new StringOverload(200);
	cout << "Binary + operation" << endl;
	temp->mystring = mystring + s.mystring;
	return temp;
}


void main()
{
	int size;
	cout << "enter string size: ";
	cin >> size;
	StringOverload *ob1=new StringOverload(size);
	StringOverload *ob2=new StringOverload(*ob1, size);
	cout << *ob2;
	*ob2 = *ob2 + *ob1;
	_getch();
}