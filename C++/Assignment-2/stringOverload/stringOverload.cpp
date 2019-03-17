#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>
#define MAX 100
//#include<stdlib.h>
using namespace std;

class StringOverload
{
	char *mystring;

public:
	StringOverload()
	{
		mystring = new char[MAX];
		cout << "default constructor" << endl;
	}
	StringOverload(int size)
	{
		mystring = new char[size];
		cout << "one arg constructor" << endl;
	}
	
	StringOverload(StringOverload &ob, int size)
	{
		mystring = new char[size];
		mystring = ob.mystring;
		cout << "copy constructor" << endl;
	}

	friend istream& operator>>(istream& cin, StringOverload &s);
	friend ostream& operator<<(ostream& cout, StringOverload s);
	StringOverload operator+(StringOverload &s);
	char* operator=(StringOverload &s);
	char operator[](int location);


	~StringOverload()
	{
		//
		//delete mystring;
		cout << "Destructor" << endl;
	}
};


istream& operator>>(istream& cin, StringOverload &s)
{
	cout << "enter string: ";
	cin.get(s.mystring,'\n');
	return cin;
}

ostream& operator<<(ostream& cout, StringOverload s)
{
	cout << "String is: "<< s.mystring << endl;
	return cout;
}

StringOverload StringOverload::operator+(StringOverload &s)
{
	StringOverload temp;
	cout << "Binary + operation" << endl;
	strcpy(temp.mystring, mystring);
	strcat(temp.mystring, s.mystring);
	return temp;
}

char* StringOverload::operator=(StringOverload &s)
{
	cout << "= overload operation" << endl;
	strcpy(mystring, s.mystring);
	return mystring;
}

char StringOverload::operator[](int location)
{
	return mystring[location];
}


void main()
{
	StringOverload ob1(MAX);
	cin >> ob1;
	cout << ob1;
	StringOverload ob2(ob1, MAX);
	StringOverload ob3;
	ob3 = ob2;
	cout <<"After = overload, "<< ob3;
	ob3 = ob2 + ob1;
	cout<<"After binary +, "<<ob3;
	cout << "After [] overload, " << ob3[2]<<endl;
	
	ob1.~StringOverload();
	ob2.~StringOverload();
	ob3.~StringOverload();

	_getch();
}