#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#define MAX 100
#define SIZE 3
using namespace std;

class MyStringClass
{
	char *name;
	int length;

public:
	MyStringClass()
	{
		name = new char[MAX];
		length = 0;
		cout << "This is default constructor" << endl;
	}
	MyStringClass(int len)
	{

		length = len;
		name = new char[len + 1];
		cout << "This is parameterized constructor" << endl;
	}

	MyStringClass(MyStringClass &obj)
	{
		length = obj.length;
		name = new char[length + 1];
		name = obj.name;
		cout << "This is copy constructor" << endl;
	}

	friend istream& operator >> (istream& cin, MyStringClass &obj);
	friend ostream& operator<<(ostream& cout, MyStringClass obj);
	MyStringClass operator+(MyStringClass &obj);
	MyStringClass operator=(MyStringClass &obj);
	friend void sorting(MyStringClass obarr[]);

	~MyStringClass()
	{
		cout << "This is destructor" << endl;
	}
};


istream& operator >> (istream& cin, MyStringClass &obj)
{
	cout << "Enter name: ";
	cin.get(obj.name, '\n');
	return cin;
}

ostream& operator<<(ostream& cout, MyStringClass obj)
{
	cout << "Name is: " << obj.name << endl;
	return cout;
}

MyStringClass MyStringClass::operator+(MyStringClass &obj)
{
	MyStringClass temp;
	strcpy(temp.name, name);
	strcat(temp.name, obj.name);
	return temp;
}

MyStringClass MyStringClass::operator=(MyStringClass &obj)
{
	strcpy(name, obj.name);
	return *this;
}


void sorting(MyStringClass ob_arr[])
{
	//cout << "enter 3 names:\n";
	//for (int i = 0; i < SIZE; i++)
	//{
	//	
	//	//cin.get(ob_arr[i].name, '\n');
	//	cin >> ob_arr[i];
	//}
	ob_arr[0].name = "navya";
	ob_arr[1].name = "bhavya";
	ob_arr[2].name = "sravya";

	cout << "the names are: \n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << ob_arr[i].name << "\n";
	}

	char *temp = NULL;
	for (int i = 0; i < SIZE; i++)
	{
		int flag = 0;
		for (int j = 0; j < SIZE - 1 - i; j++)
		{
			if (strcmp(ob_arr[j].name, ob_arr[j + 1].name) > 0 )
			{
				flag = 1;
				temp = ob_arr[j].name;
				ob_arr[j].name = ob_arr[j+1].name;
				ob_arr[j + 1].name = temp;
			}
		}
		if (flag == 0)
			break;
	}
	cout << "the names are: \n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << ob_arr[i].name << "\n";
	}

}


void main()
{
	cout << "Enter object 1 details: ";
	MyStringClass obj1(MAX);
	cin >> obj1;

	cout << "OBJECT - 1: " << endl;
	cout << obj1;
	MyStringClass obj2(obj1);
	cout << "OBJECT - 2: " << endl;
	cout << obj2;

	MyStringClass obj3;
	
	obj3 = obj2 + obj1;
	cout << "OBJECT - 3: " << endl;
	cout << obj3;
	
	obj1 = obj3;
	cout << "After = overload: ";
	cout << obj1;

	MyStringClass ob_arr[SIZE];
	sorting(ob_arr);

	obj1.~MyStringClass();
	obj2.~MyStringClass();
	obj3.~MyStringClass();

	system("pause");
}